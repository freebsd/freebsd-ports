# New ports collection makefile for:	ccl
# Date created:		2010-01-03
# Whom:			Jimmy Olgeni <olgeni@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ccl
PORTVERSION=	1.5
CATEGORIES=	lang lisp
MASTER_SITES=	ftp://ftp.clozure.com/pub/release/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-freebsdx86

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Clozure CL is a free Common Lisp implementation

WRKSRC=		${WRKDIR}/ccl

ONLY_FOR_ARCHS=	i386 amd64

MANUAL_PACKAGE_BUILD=yes

CCL_DIRECTORY=	${PREFIX}/lib/ccl
CCL_PLIST=	${WRKDIR}/pkg-plist
# the following files will not be installed
EXCLUDE=	cocoa-ide lisp-kernel scripts

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
LISP_ARCH=	x8632
FX86CL=		fx86cl
EXCLUDE+=	fx86cl64 fx86cl64.image
.elif ${ARCH} == "amd64"
LISP_ARCH=	x8664
FX86CL=		fx86cl64
EXCLUDE+=	fx86cl fx86cl.image
.endif

SUB_LIST+=	FX86CL="${FX86CL}" CCL_DIRECTORY="${CCL_DIRECTORY}"
SUB_FILES=	ccl.sh

post-patch:
	@${SED}	-i '' -e 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/tools/asdf.lisp
	@${FIND} ${WRKSRC} -name .svn -or -name .cvsignore -or -name "*.orig" \
		| ${XARGS} ${RM} -r -f

do-build:
	@${RM} -f ${WRKSRC}/fx86cl ${WRKSRC}/fx86cl64
	@cd ${WRKSRC}/lisp-kernel/freebsd${LISP_ARCH} && ${MAKE} && ${RM} -f *.o
	@cd ${WRKSRC} && if ! ${ECHO_CMD} | ./${FX86CL} --batch --quiet >/dev/null 2>&1; then \
		${ECHO_MSG} "===>  This CPU doesn't support the SSE2 instruction set: cannot build port."; \
		exit 1; \
	fi
	@cd ${WRKSRC} && ${ECHO_CMD} | ./${FX86CL} --no-init --batch --quiet \
		--eval "(ccl:rebuild-ccl :full t)" \
		--eval "(require 'asdf)" \
		--eval "(asdf:operate 'asdf:load-op 'asdf-install)" \
		--eval "(quit)"

do-install:
	@${MKDIR} ${CCL_DIRECTORY}
	@${CP} -r ${WRKSRC}/* ${CCL_DIRECTORY}
	@for i in ${EXCLUDE}; do \
		${RM} -r -f ${CCL_DIRECTORY}/$${i}; \
	done
	@${INSTALL_SCRIPT} ${WRKDIR}/ccl.sh ${PREFIX}/bin/ccl

post-install:
	@cd ${PREFIX}; ${FIND} lib/ccl/* -type d -empty \
		| ${SORT} \
		| ${SED} -e 's#^#@exec ${MKDIR} %D/#g' \
		> ${CCL_PLIST}
	@cd ${PREFIX}; ${FIND} lib/ccl/* -type f -o -type l \
		| ${SORT} \
		>> ${CCL_PLIST}
	@cd ${PREFIX}; ${FIND} lib/ccl/* -type d | ${SORT} -r \
	    	| ${SED} -e 's/^/@dirrm /g' \
		>> ${CCL_PLIST}
	@${ECHO_CMD} "r ${TMPPLIST}"		> ${WRKDIR}/ex.script
	@${ECHO_CMD} "/start"			>> ${WRKDIR}/ex.script
	@${ECHO_CMD} "r ${CCL_PLIST}"		>> ${WRKDIR}/ex.script
	@${ECHO_CMD} "x!"			>> ${WRKDIR}/ex.script
	@cd ${WRKDIR} && ex < ex.script > /dev/null
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
