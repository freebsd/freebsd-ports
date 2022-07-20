PORTNAME=	cut
PORTVERSION=	2.7
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://bitbucket.org/kc5tja/cut/get/
DISTNAME=	v${PORTVERSION}
DIST_SUBDIR=	cut

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Unit Testing Framework for C, C++, and Objective-C

LICENSE=	BSD3CLAUSE

WRKSRC=		${WRKDIR}/kc5tja-cut-d4fc09276ea9

USES=		python:run shebangfix tar:bzip2
SHEBANG_FILES=	*.py
ALL_TARGET=	build

PLIST_SUB=	VERSION="${PORTVERSION}"

OPTIONS_DEFINE=	DOCS

do-configure:
	@${ECHO_CMD} -n > ${WRKDIR}/cutgen
	@${ECHO_CMD} "#!${SH}" >> ${WRKDIR}/cutgen
	@${ECHO_CMD} "cd ${PYTHONPREFIX_SITELIBDIR}/cut" >> ${WRKDIR}/cutgen
	@${ECHO_CMD} "exec ${PYTHON_CMD:T} cutgen.py" >> ${WRKDIR}/cutgen

do-install:
	(cd ${WRKDIR} && ${INSTALL_SCRIPT} cutgen \
		${STAGEDIR}${PREFIX}/bin)
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/cut/${PORTVERSION}
	(cd ${WRKSRC} && ${INSTALL_DATA} cut.h \
		${STAGEDIR}${PREFIX}/include/cut/${PORTVERSION})
	(cd ${WRKSRC}/build/lib && ${INSTALL_DATA} libcut.a \
		${STAGEDIR}${PREFIX}/lib)
	@${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/cut
	(cd ${WRKSRC} && ${INSTALL_DATA} *.py \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/cut)

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} index.html \
		${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
