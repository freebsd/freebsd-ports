PORTNAME=	moony
DISTVERSION=	0.40.0
CATEGORIES=	audio
MASTER_SITES=	https://git.open-music-kontrollers.ch/~hp/moony.lv2/archive/
PKGNAMESUFFIX=	-lv2
DISTNAME=	${DISTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Realtime Lua as programmable glue in LV2
WWW=		https://open-music-kontrollers.ch/lv2/moony

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	lv2>0:audio/lv2
LIB_DEPENDS=	libvterm.so:devel/libvterm

USES=		compiler:c++11-lang gl meson pkgconfig xorg
USE_XORG=	x11 xext
USE_GL=		gl glew glu

WRKSRC=		${WRKDIR}/${PORTNAME}.lv2-${DISTVERSION}

.include <bsd.port.mk>
