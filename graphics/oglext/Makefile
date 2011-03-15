# New ports collection makefile for: oglext
# Date created:		01 Feb 2004
# Whom:			Igor Pokrovsky <tiamat@comset.net>
#
# $FreeBSD$
#

PORTNAME=	oglext
PORTVERSION=	1.2.2
PORTREVISION=	2
CATEGORIES=	graphics devel
MASTER_SITES=	http://www.julius.caesar.de/files/oglext/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A library for easier access to OpenGL extensions

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

BUILD_DEPENDS=	${LOCALBASE}/bin/tmake:${PORTSDIR}/devel/tmake

USE_GMAKE=	yes
USE_GL=		gl glu
USE_XORG=	xmu xext x11
USE_LDCONFIG=	yes
REINPLACE_ARGS=	-i ""

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
BUILD_WRKSRC=	${WRKSRC}/src
ALL_TARGET=	all staticlib

TMAKE?=		${LOCALBASE}/bin/tmake
TMAKEPATH?=	${LOCALBASE}/share/tmake/freebsd-g++

# a quick hack to fix dir's permissions
post-extract:
	@(for i in 1 2; do \
		${FIND} ${WRKSRC} -type d 2>/dev/null \
			| ${XARGS} ${CHMOD} u+x; \
	done)

pre-patch:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${REINPLACE_CMD} -e "s/`${PRINTF} '\r'`//"

pre-build:
	${SETENV} TMAKEPATH=${TMAKEPATH} \
		${TMAKE} ${WRKSRC}/build/OglExt.pro >${BUILD_WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/libOglExt.so.1 ${PREFIX}/lib
	${LN} -sf ${PREFIX}/lib/libOglExt.so.1 ${PREFIX}/lib/libOglExt.so
	${INSTALL_DATA} ${BUILD_WRKSRC}/libOglExt.a ${PREFIX}/lib
# install includes in separate dir to avoid conflicts with Mesa
	@${MKDIR} ${PREFIX}/include/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/include/*.h ${PREFIX}/include/${PORTNAME}
.ifndef (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
