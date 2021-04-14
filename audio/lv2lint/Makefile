PORTNAME=	lv2lint
DISTVERSION=	0.12.0
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Check whether a given LV2 plugin is up to the specification

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	lv2>0:audio/lv2 \
		curl>0:ftp/curl \
		libelf>0:devel/libelf
LIB_DEPENDS=	liblilv-0.so:audio/lilv
RUN_DEPENDS=	curl>0:ftp/curl \
		libelf>0:devel/libelf

USES=		compiler:c++11-lang meson pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	OpenMusicKontrollers

PLIST_FILES=	bin/lv2lint \
		man/man1/lv2lint.1.gz

.include <bsd.port.mk>
