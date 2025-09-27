PORTNAME=	openuniverse
DISTVERSION=	1.0beta3
PORTREVISION=	16
CATEGORIES=	astro
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTVERSION}

MAINTAINER=	mew14930xvi@inbox.lv
COMMENT=	OpenGL Solar System simulator for X Window System
WWW=		https://openuniverse.sourceforge.net/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gl gmake jpeg localbase xorg
USE_CXXSTD=	c++98
USE_GL=		gl glu glut
USE_XORG=	ice sm x11 xext xi xmu xorgproto

GNU_CONFIGURE=	yes

LIBS+=		-lutil

.include <bsd.port.mk>
