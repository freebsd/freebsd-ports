# Created by: Sergei Kolobov <sergei@kolobov.com>
# $FreeBSD$

PORTNAME=	skalibs
PORTVERSION=	0.47
CATEGORIES=	devel
MASTER_SITES=	http://www.skarnet.org/software/${PORTNAME}/

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	General purpose C libraries used by skarnet.org software

USE_GCC=	any

LDFLAGS?=	-s
STRIPFLAGS?=	-x

WRKSRC=		${WRKDIR}/prog/${DISTNAME}

DOCS=		package/CHANGES package/README package/THANKS doc/*.html

do-configure:
	${ECHO_CMD} "${CC} ${CFLAGS}"	> ${WRKSRC}/conf-compile/conf-cc
	${ECHO_CMD} "${CC} ${LDFLAGS}"	> ${WRKSRC}/conf-compile/conf-ld
	${ECHO_CMD} "${STRIP_CMD} ${STRIPFLAGS}" \
					> ${WRKSRC}/conf-compile/conf-striplibs

do-build:
	cd ${WRKSRC} && package/compile

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/include/* ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/library/* ${STAGEDIR}${PREFIX}/lib/${PORTNAME}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
