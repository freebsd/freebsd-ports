# New ports collection makefile for:	skalibs
# Date created:		2003-06-25
# Whom:			Sergei Kolobov <sergei@kolobov.com>
#
# $FreeBSD$
#

PORTNAME=	skalibs
PORTVERSION=	0.45
CATEGORIES=	devel
MASTER_SITES=	http://www.skarnet.org/software/${PORTNAME}/

MAINTAINER=	sergei@FreeBSD.org
COMMENT=	General purpose C libraries used by skarnet.org software

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
	@${MKDIR} ${PREFIX}/include/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/include/* ${PREFIX}/include/${PORTNAME}
	@${MKDIR} ${PREFIX}/lib/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/library/* ${PREFIX}/lib/${PORTNAME}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
