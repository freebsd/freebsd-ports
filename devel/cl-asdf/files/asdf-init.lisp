;;;; asdf-config.lisp - Setup ASDF to deal with FBSD ports conventions

;; Copyright (c) 2003 Henrik Motakef <henrik.motakef@web.de>

;; Redistribution and use  in source and binary   forms, with or  without
;; modification, are permitted provided that the following conditions are
;; met:                                                                  

;; 1. Redistributions  of  source  code  must retain  the above copyright
;;    notice, this list of conditions and the following disclaimer.      
;; 								      
;; 2. Redistributions in  binary form must reproduce  the above copyright
;;    notice, this list of conditions and the following disclaimer in the
;;    documentation and/or other materials provided with the distribution

;; THIS  SOFTWARE   IS PROVIDED ``AS  IS''   AND ANY  EXPRESS  OR IMPLIED
;; WARRANTIES, INCLUDING, BUT NOT LIMITED  TO, THE IMPLIED WARRANTIES  OF
;; MERCHANTABILITY  AND FITNESS FOR A  PARTICULAR PURPOSE ARE DISCLAIMED.
;; IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
;; INDIRECT,  INCIDENTAL,  SPECIAL, EXEMPLARY,  OR CONSEQUENTIAL  DAMAGES
;; (INCLUDING, BUT NOT LIMITED TO,   PROCUREMENT OF SUBSTITUTE GOODS   OR
;; SERVICES;  LOSS OF  USE,  DATA, OR  PROFITS; OR BUSINESS INTERRUPTION)
;; HOWEVER  CAUSED AND ON ANY THEORY  OF LIABILITY,  WHETHER IN CONTRACT,
;; STRICT LIABILITY, OR  TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
;; IN ANY WAY  OUT OF THE  USE OF THIS SOFTWARE,  EVEN IF ADVISED OF  THE
;; POSSIBILITY OF SUCH DAMAGE.

;;;; How to use

;; A number of FreeBSD ports related to Common Lisp use the asdf
;; system definition library, available as devel/cl-asdf-* (which you
;; obviously already have installed, scince this file is included with
;; that port). That implies that you will have to load and configure
;; asdf to use these ports with your Lisp system.
;;
;; This file takes all neccessary actions. The easiest way is to load
;; it in your Lisp everytime it starts, by putting
;;
;;  (load "/usr/local/etc/freebsd-lisp-init")
;;
;; in your init file.
;;
;; Each Lisp implementation has it's own files where this can be done:
;;
;; CLISP:
;;   /usr/local/lib/clisp/config.lisp
;;   ~/.clisprc
;;
;; CMUCL:
;;   /usr/local/lib/cmucl/lib/cmucl/lib/site-init.lisp
;;   ~/.cmucl-init.lisp
;;
;; SBCL:
;;  /usr/local/etc/sbclrc
;;  ~/.sbclrc
;;
;; After that, you can load your installed ports like this (using
;; textproc/cl-ppcre as an example):
;;
;;    (asdf:operate 'asdf:load-op 'cl-ppcre)
;;

;; Have fun!


;;;; What's going on here

;; We mess around with asdf:output-files in interesting ways to
;; enforce a filesystem layout that works without multiple Lisp
;; implementations overwriting their fasls. Basically, each lib has
;; it's own directory in /usr/local/lib/common-lisp, initially
;; containing its sources. Each fasl port will create an
;; implementation-specific subdirectory where all it's fasls go, for
;; example ./cmuclfasl, ./clispfasl etc.

;; Additionally, all fasl files have the pathname-type "fasl", not
;; "x86f" or "fas". The reason is that I want to be prepared for the
;; case that CMUCL some lucky day might be supported on non-x86
;; archs. Scince it encodes the arch in the fasl file-type (x86f,
;; sparcf etc), hardcoding this in pkg-plists would then
;; break. Enforcing this policy for all implementations (for example,
;; CLISP uses .fas by default) simply is more convenient then handling
;; CMUCL specially.

;; The drawback is that users cannot easily load compiled code unless
;; they set up asdf properly, which boils down to loading this file
;; instead of asdf.lisp directly.

;; Yet another thing that has to be handled is compiling ports: During
;; 'make build', no files outside of ${WRKSRC} may be created. On the
;; other hand, it is a good idea to use the source files from their
;; final location, because CMUCL and SBCL record the source path and
;; can use, for example, to show the misbehaving form in the debugger.
;; And the fasl ports depend on the source port to be installed
;; anyway, because of the .asd file.
;; Hence, in the case of port compilation, we redirect the output to
;; ${WRKSRC}. This situation is detected by checking if an environment
;; variable FBSD_ASDF_COMPILE_PORT is set (and if we have a WRKSRC
;; envvar as well), so each port Makefile has to create this variable
;; in the envorinment in which it calls Lisp in do-build, see existing
;; ports for examples.

;; Note that it is only neccessary to modify
;; (output-files ((op compile-op)) ...), because asdf:load-op will use
;; this method too to decide which files are to be loaded, there is no
;; separate method for load-op.

;;;; Adding support for other Lisp implementations

;; In order to make all this work for not-handled-yet Lisps, it is
;; only neccessary to change LISP-SPECIFIC-FASL-SUDBIR and GETENV. Of
;; course, you'll also have to create new binary ports, if that's what
;; you want.



;;;; Package declaration

(defpackage :freebsd-asdf
  (:use :common-lisp)
  (:export #:*asdf-pathname*
	   #:unsupported-lisp-implementation))

(in-package :freebsd-asdf)

;;;; Pathes

(defvar *asdf-pathname*
  "/usr/local/lib/common-lisp/asdf/asdf"
  "Path of the ASDF library")

(defvar *system-registry*
  "/usr/local/lib/common-lisp/system-registry"
  "FreeBSDs contribution to the entral registry for ASDF system
definitions.  This will be added to asdf:*central-registry*, you
should modify that in order to add other directories.")

;;;; Implementation-specific functions

(define-condition unsupported-lisp-implementation ()
  ()
  (:report (lambda (condition stream)
	     (declare (ignore condition)
		      (type stream stream))
	     (format stream "Your Lisp system, ~A ~A, is currently not ~
                             supported by the FreeBSD ports system."
		     (lisp-implementation-type)
		     (lisp-implementation-version)))))


(defun lisp-specific-fasl-subdir ()
  "Return the subdirectory in which fasl files for this Lisp
implementations should be stored, as a sting without any slashes.

If no subdirectory for the current implementation is known, signal an
error of type UNSUPPORTED-LISP-IMPLEMENTATION.

This function has to be extended for each new Lisp implementation that
should be able to use the ASDF-based Lisp ports. If you do this, you
should probably extend GETENV as well."
  #+clisp "clispfasl"
  #+cmu   "cmuclfasl"
  #+sbcl  "sbclfasl"
  #-(or clisp cmu sbcl) (error 'unsupported-lisp-implementation))

(defun getenv (varname)
  "Return the value of environment variable VARNAME, as a string.
If VARNAME is not found in the current environment, return nil.
May signal an error of type UNSUPPORTED-LISP-IMPLEMENTATION, see
below.

This is used to communicate make variables like WRKSRC from the ports
system to Lisp. Note that this doesn't happen automatically for
variables defined in a Makefile, you'll have to pass these to the
environment in which Lisp runs explicitly.

Scince accessing environment variables is not portable, this function
has to be extended for each Lisp implementation that is to work with
FreeBSDs Lisp ports. If you do this, you should probably extend
LISP-SPECIFIC-FASL-SUBDIR as well."
  #+sbcl (sb-ext:posix-getenv varname)
  #+cmu  (cdr (assoc varname ext:*environment-list* 
		     :test #'equalp
		     :key #'string))
  #+clisp (sys::getenv varname)
  #-(or sbcl cmu clisp) (error 'unsupported-lisp-implementation))


;;;; Load and configure ASDF

(defvar *asdf-binary-pathname*
  (make-pathname
   :directory `(:absolute ,@(cdr (pathname-directory *asdf-pathname*))
			  ,(lisp-specific-fasl-subdir))
   :type "fasl"
   :defaults *asdf-pathname*))

(or (ignore-errors (load *asdf-binary-pathname* :verbose t :print nil))
    (load *asdf-pathname* :verbose t :print nil))

(pushnew *system-registry* asdf:*central-registry*)

;;;; Messing with asdf:output-files

(if (and (getenv "FBSD_ASDF_COMPILE_PORT")
	 (getenv "WRKSRC"))

    ;;;; We are compiling a port - fasls should go to ${WRKSRC}
    (defmethod asdf:output-files :around ((op asdf:compile-op)
					  (file asdf:cl-source-file))
      (let ((wrksrc (getenv "WRKSRC"))
	    (relative-name (asdf:component-relative-pathname file))
	    (default-output-name (car (call-next-method))))
	(list
	 (make-pathname
	  :host (pathname-host wrksrc)
	  :device (pathname-device wrksrc)
	  :directory `(:absolute ,@(cdr (pathname-directory wrksrc))
				 ,@(cdr (pathname-directory relative-name)))
	  :name (pathname-name default-output-name)
	  :type "fasl"))))

  ;; Normal operation: load from lisp-specific-fasl-subdir
  (defmethod asdf:output-files :around ((op asdf:compile-op)
					(file asdf:cl-source-file))
    (let ((default-output-file (car (call-next-method))))
      (list
       (make-pathname
	:directory `(:absolute ,@(cdr (pathname-directory default-output-file))
			       ,(lisp-specific-fasl-subdir))
	:type "fasl"
	:defaults default-output-file))))
)


;;; freebsd-lisp-init.lisp ends here
