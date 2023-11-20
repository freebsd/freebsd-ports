PORTNAME=	pamixer
DISTVERSION=	1.6
CATEGORIES=	audio

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	Pulseaudio command line mixer
WWW=		https://github.com/cdemoulins/pamixer

LICENSE=	GPLv3

BUILD_DEPENDS=	cxxopts>0:devel/cxxopts
LIB_DEPENDS=	libpulse.so:audio/pulseaudio

USES=		compiler:c++11-lang meson pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	cdemoulins

PLIST_FILES=	bin/pamixer \
		man/man1/pamixer.1.gz

.include <bsd.port.mk>
