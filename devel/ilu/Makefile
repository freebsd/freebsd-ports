# New ports collection makefile for: ilu
# Version required:     2.0alpha12
# Date created:         29.9.1997
# Whom:                 cracauer@cons.org "Martin Cracauer"
#
# $Id: Makefile,v 1.6 1997/10/09 21:19:41 cracauer Exp $
#

DISTNAME=       ilu-2.0alpha12
PKGNAME=	ilu-2.0a12
CATEGORIES=     devel
MASTER_SITES=   ftp://parcftp.xerox.com/pub/ilu/2.0a12/

MAINTAINER=	cracauer@cons.org

NO_PACKAGE=	Doesn't work with optimization enabled

NO_WRKSUBDIR=   yes
HAS_CONFIGURE=	yes

# The official guile port is outdated. If you have 1.2 installed, remove
#   --disable-guile-support
CONFIGURE_ARGS= --disable-guile-support --enable-http-protocol

INSTALL_TARGET=	Install
NOMANCOMPRESS=
PLIST=		${WRKSRC}/PLIST

# Startup script, run at boot time
startup_dir=    ${PREFIX}/etc/rc.d
startup_script= ${startup_dir}/50.ilu.sh

post-install:
	# Empty dir, but we really need it
	${ECHO} @exec ${MKDIR} %D/ilu/lib/binding > ${PLIST}
	${ECHO} @unexec ${RM} -r %D/ilu/lib/binding >> ${PLIST}
	${ECHO} @exec chmod 777 %D/ilu/lib/binding >> ${PLIST}
	${ECHO} @exec ${LDCONFIG} -m %D/ilu/lib >> ${PLIST}
	# Empty dirs we don't need
	${RMDIR} ${PREFIX}/ilu/man/man[358]
	${RMDIR} ${PREFIX}/ilu/lisp
	# this one doesn't always exist, hence the || true
	# .if exists(${PREFIX} ... doesn't work for me
	${RMDIR} ${PREFIX}/ilu/examples/javatest1/javastubs || true
	(cd ${PREFIX} ; find ilu -type f) >> ${PLIST}
	(cd ${PREFIX} ; find ilu -type d) | ${AWK} '{print "@dirrm " $$1}' \
		| tail -r | ${GREP} -v lib/binding >> ${PLIST}
	(cd ${PREFIX}/ilu/bin ; for file in * ; do \
		ln -fs ${PREFIX}/ilu/bin/$$file ${PREFIX}/bin/. ; \
		${ECHO} @exec ln -fs %D/ilu/bin/$$file %D/bin/. ; \
		${ECHO} @unexec ${RM} %D/bin/$$file ; \
		done) >> ${PLIST}
	(cd ${PREFIX}/ilu/man/man1 ; for file in * ; do \
		ln -fs ${PREFIX}/ilu/man/man1/$$file ${PREFIX}/man/man1/. ; \
		${ECHO} @exec ln -fs %D/ilu/man/man1/$$file %D/man/man1/. ; \
		${ECHO} @unexec ${RM} %D/man/man1/$$file ; \
		done) >> ${PLIST}
	${ECHO} etc/rc.d/50.ilu.sh >> ${PLIST}
	${ECHO} "Installing ${startup_script} file"
	test -d ${startup_dir} || ${MKDIR} ${startup_dir}
	${ECHO} "#!/bin/sh" > ${startup_script}
	${ECHO} "${ECHO} -n ' ILU-shlibs'" >> ${startup_script}
	${ECHO} "${LDCONFIG} -m ${PREFIX}/ilu/lib" >> ${startup_script}
	chmod 755 ${startup_script};
	${startup_script}

.include <bsd.port.mk>
