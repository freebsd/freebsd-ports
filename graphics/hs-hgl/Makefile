# New ports collection makefile for:	hgl
# Date created:		22 January 2002
# Whom:			octaphial
#
# $FreeBSD$
#

PORTNAME=	hgl
PORTVERSION=	2.0.4
PORTREVISION=	2
CATEGORIES=	graphics haskell
MASTER_SITES=	http://haskell.org/graphics/downloads/
PKGNAMEPREFIX=	hs-
DISTNAME=	graphics-${PORTVERSION}.src

MAINTAINER=	octaphial@yahoo.com
COMMENT=	Graphics library for Hugs98, an implementation of Haskell 98

RUN_DEPENDS=	hugs:${PORTSDIR}/lang/hugs

WRKSRC=		${WRKDIR}/graphics-${PORTVERSION}
USE_GMAKE=	yes
USE_XLIB=	yes

HGL_LIBS=	${PREFIX}/lib/hugs/x11
HGL_DOCS=	${PREFIX}/share/doc/hs-hgl

BUILD_WRKSRC=	${WRKSRC}/lib/x11
MAKE_ENV=	system=FreeBSD \
		hugs_install=${HGL_LIBS}
ALL_TARGET=	all

.if ${MACHINE_ARCH:L} == "amd64"
CFLAGS+=	-fPIC
.endif

do-install:
	${MKDIR} ${HGL_LIBS}
	${MKDIR} ${HGL_LIBS}/demos
	${INSTALL_DATA} ${WRKSRC}/lib/x11/*.hs ${HGL_LIBS}
	${INSTALL_PROGRAM} ${WRKSRC}/lib/x11/*.o ${HGL_LIBS}
	${INSTALL_PROGRAM} ${WRKSRC}/lib/x11/*.so ${HGL_LIBS}
	${INSTALL_DATA} ${WRKSRC}/demos/* ${HGL_LIBS}/demos
	${INSTALL_DATA} ${WRKSRC}/test/* ${HGL_LIBS}/demos

post-install:
	${MKDIR} ${HGL_DOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${HGL_DOCS}
	${INSTALL_DATA} ${WRKSRC}/License ${HGL_DOCS}
	${INSTALL_DATA} ${WRKSRC}/Readme ${HGL_DOCS}
	${INSTALL_DATA} ${WRKSRC}/Version ${HGL_DOCS}
	${INSTALL_DATA} ${WRKSRC}/Version-2.0.4 ${HGL_DOCS}
	@${ECHO} ''
	@${CAT} ${PKGMESSAGE}
	@${ECHO} ''

.include <bsd.port.mk>
