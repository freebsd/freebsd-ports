PORTNAME=	ratatouille
DISTVERSION=	0.9.10
CATEGORIES=	audio
MASTER_SITES=	https://github.com/brummer10/Ratatouille.lv2/releases/download/v${DISTVERSION}/
PKGNAMESUFFIX=	-lv2
DISTNAME=	Ratatouille.lv2-v${DISTVERSION}-src

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Neural model loader and mixer
WWW=		https://github.com/brummer10/Ratatouille.lv2

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	lv2>0:audio/lv2 \
		xxd:sysutils/xxd
LIB_DEPENDS=	libjack.so:audio/jack \
		libsndfile.so:audio/libsndfile

USES=		compiler:c++20-lang gmake gnome localbase pkgconfig tar:xz xorg
USE_GNOME=	cairo
USE_XORG=	x11

WRKSRC=		${WRKDIR}/Ratatouille.lv2-v${DISTVERSION}

MAKEFILE=	makefile

.include <bsd.port.mk>
