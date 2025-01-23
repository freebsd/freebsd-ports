PORTNAME=	mda-lv2
DISTVERSION=	1.2.10
CATEGORIES=	audio
MASTER_SITES=	http://download.drobilla.net/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	LV2 port of the MDA plugins by Paul Kellett
WWW=		https://drobilla.net/software/mda-lv2

LICENSE=	GPLv3
#LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	lv2>0:audio/lv2 \
		lv2lint>0:audio/lv2lint

USES=		meson pkgconfig tar:xz

MESON_ARGS=	-Dtests=disabled

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lv2/mda.lv2/*.so

.include <bsd.port.mk>
