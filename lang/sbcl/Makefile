# New ports collection makefile for:	sbcl
# Date created:				2002-11-26
# Whom:					des
#
# $FreeBSD$
#
# Note: If you update this port make sure you create the distfinfo for all
# versions: sbcl-1.v.v-x86-64-freebsd and sbcl-1.v.v-x86-freebsd
#

PORTNAME=	sbcl
PORTVERSION=	1.0.49.0
PORTREVISION=	0
PORTEPOCH=	1
CATEGORIES=	lang lisp
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION:R} \
		ftp://ftp.SpringDaemons.com/soft/sbcl-binary/:binaries
#MASTER_SITES=	ftp://ftp.SpringDaemons.com/soft/ \
#		ftp://ftp.SpringDaemons.com/soft/sbcl-binary/:binaries
#MASTER_SITE_SUBDIR=	sbcl/${PORTVERSION:R}
DISTNAME=	${PORTNAME}-${PORTVERSION:R}-source${SBCLPATCHLEVEL}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Common Lisp development system derived from the CMU CL system

# More platforms are supported, but on Linux.
ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	is a native code compiler, and has not been ported to this architecture yet

USE_BZIP2=	yes
USE_GMAKE=	yes
CFLAGS+=	-DSBCL_HOME=\\\"${SBCL_HOME}\\\"
CPPFLAGS+=	-I.
SBCL_HOME=	${PREFIX}/lib/sbcl/

OPTIONS=	SBCL "Use installed SBCL binary if available" off \
		THREADS "Enable experimental threading support" off \
		PDF "Build PDF documentation" on \
		PS "Build PostScript documentation" off

#LICENSE=	BSD
#LICENSE_FILE=	${WRKSRC}/COPYING
MAN1=		sbcl.1
INFODIR=	${PREFIX}/${INFO_PATH}
.if !defined(NOPORTDOCS)
INFO=	${MANUALS_SRC} sbcl-internals
MANUALS_SRC=	asdf sbcl
TEXTDOCS=	BUGS CREDITS COPYING NEWS PRINCIPLES STYLE TLA TODO
MANUALS=	${MANUALS_SRC:S,$,.html,g}
MODULESDOCS=	asdf/README asdf/README.SBCL	\
		asdf-install/README 		\
		sb-aclrepl/README		\
		sb-bsd-sockets/FAQ sb-bsd-sockets/NEWS \
		sb-md5/README			\
		sb-posix/README			\
		sb-rotate-byte/README		\
		sb-simple-streams/README
.endif

OSVER_MAJOR=	${OSVERSION:C/([0-9]).*/\1/}
NEWBOOTNAME=	${PORTNAME}-${PORTVERSION:R}-${ARCH}-freebsd${OSVER_MAJOR}
DOC_TARGETS=	info html
CONTRIB_MODULES=	asdf			\
			asdf-install		\
			sb-aclrepl		\
			sb-bsd-sockets		\
			sb-cltl2		\
			sb-concurrency		\
			sb-cover		\
			sb-executable		\
			sb-grovel		\
			sb-introspect		\
			sb-md5			\
			sb-posix		\
			sb-queue		\
			sb-rotate-byte		\
			sb-rt			\
			sb-simple-streams	\
			sb-sprof

.if ${PORTVERSION:E} == 0
SBCLPATCHLEVEL=	#empty
.else
SBCLPATCHLEVEL=	-r${PORTVERSION:E}
.endif

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}

.include <bsd.port.pre.mk>

.if !defined(NOPORTDOCS) || !defined(WITHOUT_PDF) || !defined(WITHOUT_PS)
BUILD_DEPENDS=	dot:${PORTSDIR}/graphics/graphviz
.endif

.if !defined(WITHOUT_PDF)
BUILD_DEPENDS+=	latex:${PORTSDIR}/print/teTeX-base \
		texi2dvi:${PORTSDIR}/print/texinfo
DOC_TARGETS+=	pdf
PLIST_SUB+=	PDF=""
. if !defined(NOPORTDOCS)
MANUALS+=	${MANUALS_SRC:S,$,.pdf,g}
. endif
.else
PLIST_SUB+=	PDF="@comment "
.endif

.if defined(WITH_PS)
BUILD_DEPENDS+=	dvips:${PORTSDIR}/print/dvips
DOC_TARGETS+=	ps
PLIST_SUB+=	PS=""
. if !defined(NOPORTDOCS)
MANUALS+=	${MANUALS_SRC:S,$,.ps,g}
. endif
.else
PLIST_SUB+=	PS="@comment "
.endif

.if ${ARCH} == "i386"
PLIST_SUB+=	I386_ONLY="" AMD64_ONLY="@comment "
SBCLCONFIG=	 Config.x86-freebsd
DYNAMIC_SPACE_SIZE?=	512
.else
PLIST_SUB+=	I386_ONLY="@comment " AMD64_ONLY=""
SBCLCONFIG=	Config.x86-64-freebsd
.endif

# If WITH_SBCL is defined, try to use existing "sbcl" first.
.if defined(WITH_SBCL) && exists(${LOCALBASE}/bin/sbcl)
LISP_CMD=	""
.else
BOOT_VERSION=	1.0.31

. if make(makesum)
BOOT_ARCH_OS_LIST=	amd64-freebsd8 amd64-freebsd7 amd64-freebsd6 \
			i386-freebsd8 i386-freebsd7 i386-freebsd6
. else
.  if ${OSVER_MAJOR} == 9	# We'll use 8.x bootstrap for now
BOOT_ARCH_OS_LIST=	${ARCH}-freebsd8
.  else
BOOT_ARCH_OS_LIST=	${ARCH}-freebsd${OSVER_MAJOR}
.  endif
. endif

. ifdef(DYNAMIC_SPACE_SIZE)
LISP_EXTRA_ARG=	--dynamic-space-size ${DYNAMIC_SPACE_SIZE}
. endif

DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
. for BOOT_ARCH_OS in ${BOOT_ARCH_OS_LIST}
BOOT_DISTNAME=	${PORTNAME}-${BOOT_VERSION}-${BOOT_ARCH_OS}
DISTFILES:=	${DISTFILES} ${BOOT_DISTNAME}-binary${EXTRACT_SUFX}:binaries
. endfor
LISP_CMD=	"${WRKDIR}/${BOOT_DISTNAME}/src/runtime/sbcl --core ${WRKDIR}/${BOOT_DISTNAME}/output/sbcl.core ${LISP_EXTRA_ARG} --disable-debugger --userinit /dev/null --sysinit /dev/null"

.endif # defined(WITH_SBCL)

.if ${OSVERSION} < 700000
BROKEN=		does not build on 6.X
.endif

pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "---------------------------------------------------------"
	@${ECHO_MSG} "You might need to increase memory limits in order to"
	@${ECHO_MSG} "build SBCL."
	@${ECHO_MSG}
	@${ECHO_MSG} "You can use the DYNAMIC_SPACE_SIZE knob to tweak the size"
	@${ECHO_MSG} "of SBCL dynamically allocated memory."
	@${ECHO_MSG} "---------------------------------------------------------"
	@${ECHO_MSG}

post-patch:
	@${ECHO_CMD} "CC=${CC}" >> ${WRKSRC}/src/runtime/${SBCLCONFIG}
	@${ECHO_CMD} "CFLAGS=${CFLAGS} -fno-omit-frame-pointer" >> \
	    ${WRKSRC}/src/runtime/${SBCLCONFIG}
	@${ECHO_CMD} "CPPFLAGS=${CPPFLAGS}" >> \
	    ${WRKSRC}/src/runtime/${SBCLCONFIG}
	@${ECHO_CMD} "GREP=${GREP}" >> ${WRKSRC}/src/runtime/${SBCLCONFIG}
	@${ECHO_CMD} "LD=${LD}" >> ${WRKSRC}/src/runtime/${SBCLCONFIG}
	@${ECHO_CMD} "LINKFLAGS=${LDFLAGS} -dynamic -rdynamic" >> \
	    ${WRKSRC}/src/runtime/${SBCLCONFIG}
	@${REINPLACE_CMD} -E -e 's,-lthr,-pthread,g' \
	    -e 's,-lpthread,-pthread,g' ${WRKSRC}/src/runtime/${SBCLCONFIG}
.ifdef(NM)
	@${ECHO_CMD} "NM=${NM} -gp" >> ${WRKSRC}/src/runtime/${SBCLCONFIG}
.endif
	@${REINPLACE_CMD} \
		-e 's|/etc/sbclrc|${PREFIX}&|g' \
		-e 's|/usr/local|${PREFIX}|g' \
		${WRKSRC}/doc/sbcl.1 \
		${WRKSRC}/doc/manual/*.texinfo \
		${WRKSRC}/src/code/toplevel.lisp
	@${REINPLACE_CMD} -e '\|CC=|s|gcc|${CC}|'  ${WRKSRC}/contrib/asdf-module.mk
	@${REINPLACE_CMD} -e 's|"cc"|"${CC}"|' \
		-e 's|"-O3"|"${CFLAGS}"|' \
			${WRKSRC}/tests/swap-lispobjs.impure.lisp
	@${REINPLACE_CMD} -e 's|cc -c|${CC} -c|' \
		-e 's|ld \$$SO_FLAGS|${LD} \$$SO_FLAGS|' \
			 ${WRKSRC}/tests/foreign.test.sh
	@${FIND} ${WRKSRC} \( -name '*.orig' -o -name '*.bak' \) -delete
.if defined(WITH_THREADS)
	@${CP} ${FILESDIR}/customize-target-features.lisp ${WRKSRC}
.endif
	@${REINPLACE_CMD} -E -e 's,makeinfo,makeinfo --no-split,g' \
		${WRKSRC}/doc/internals/Makefile

do-build:
	@(cd ${WRKSRC} && ${SETENV} CC="${CC}" INSTALL_ROOT=${PREFIX} \
		LISP_EXTRA_ARG="${LISP_EXTRA_ARG}" \
		${SH} make.sh ${LISP_CMD})
	@${RM} -rf ${WRKSRC}/contrib/sb-cover/test-output
.if !defined(NOPORTDOCS)
	@(cd ${WRKSRC}/doc/manual && ${SETENV} \
		LISP_EXTRA_ARG="${LISP_EXTRA_ARG}" \
		${GMAKE} MAKEINFO='makeinfo --no-split' ${DOC_TARGETS})
	@(cd ${WRKSRC}/doc/internals && ${GMAKE} sbcl-internals.info)
.endif
.if !defined(WITHOUT_PDF)
	@(cd ${WRKSRC}/doc/internals && ${GMAKE} sbcl-internals.pdf)
.endif
	@${REINPLACE_CMD} -E -e \
		's|\$$Date\$$|'"`${SETENV} LANG=C /bin/date '+%B %d, %Y'`|g" \
		${WRKSRC}/doc/sbcl.1

do-install:
	${MKDIR} ${SBCL_HOME}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/
.endif
	${INSTALL_PROGRAM} ${WRKSRC}/src/runtime/sbcl ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/output/sbcl.core ${SBCL_HOME}/
.for MOD in ${CONTRIB_MODULES}
	${MKDIR} ${SBCL_HOME}/${MOD}
	${INSTALL_DATA} ${WRKSRC}/contrib/${MOD}/*.lisp ${SBCL_HOME}/${MOD}/
	${INSTALL_DATA} ${WRKSRC}/contrib/${MOD}/*.fasl ${SBCL_HOME}/${MOD}/
	(if test -f ${WRKSRC}/contrib/${MOD}/${MOD}.asd; then ${INSTALL_DATA} \
	    ${WRKSRC}/contrib/${MOD}/${MOD}.asd ${SBCL_HOME}/${MOD}/; fi)
.endfor
.if !defined(NOPORTDOCS)
	${INSTALL_DATA} ${MANUALS_SRC:S,^,${WRKSRC}/doc/manual/,g:S,$,.info,g} \
	    ${INFODIR}/
	${INSTALL_DATA} ${WRKSRC}/doc/internals/sbcl-internals.info \
	    ${INFODIR}/
.if !defined(WITHOUT_PDF)
	${INSTALL_DATA} ${WRKSRC}/doc/internals/sbcl-internals.pdf \
	    ${DOCSDIR}/
.endif
	${INSTALL_DATA} ${MANUALS:S,^, ${WRKSRC}/doc/manual/,g} ${DOCSDIR}/
	${INSTALL_DATA} ${TEXTDOCS:S,^,${WRKSRC}/,g} ${DOCSDIR}/
	${MKDIR} ${MODULESDOCS:C,/[^/]+$,,g:u:S,^,${DOCSDIR}/,g}
. for MODDOC in ${MODULESDOCS}
	${INSTALL_DATA} ${WRKSRC}/contrib/${MODDOC} ${DOCSDIR}/${MODDOC}
. endfor
.endif
	${INSTALL_MAN} ${WRKSRC}/doc/sbcl.1 ${MAN1PREFIX}/man/man1
	${MKDIR} ${SBCL_HOME}/site-systems
	@${TOUCH} ${SBCL_HOME}/site-systems/.keep_me

test:	build
	(cd ${WRKSRC}/tests && ${SETENV} CC="${CC}" LISP_EXTRA_ARG="${LISP_EXTRA_ARG}" ${SH} run-tests.sh)

bootstrap:
	${CP} -r ${WRKSRC} ${WRKDIR}/${NEWBOOTNAME}
	(cd ${WRKDIR}/ && \
	    ${WRKDIR}/${NEWBOOTNAME}/binary-distribution.sh ${NEWBOOTNAME})
	(cd ${WRKDIR}/ && ${BZIP2_CMD} ${NEWBOOTNAME}-binary.tar)

.include <bsd.port.post.mk>
