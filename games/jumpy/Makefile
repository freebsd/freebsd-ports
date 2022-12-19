PORTNAME=	jumpy
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.3
PORTREVISION=	4
CATEGORIES=	games

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Tactical 2D shooter in fishy pixels style
WWW=		https://fishfight.org/

LICENSE=	CC-BY-NC-4.0 MIT
LICENSE_COMB=	multi
LICENSE_FILE_MIT=	${WRKSRC}/licenses/LICENSE-MIT

LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libudev.so:devel/libudev-devd
RUN_DEPENDS=	${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:audio/alsa-plugins

USES=		cargo gl localbase:ldflags xorg
USE_GITHUB=	yes
USE_GL=		gl
USE_XORG=	x11 xi
GH_ACCOUNT=	fishfolks
PLIST_FILES=	bin/${PORTNAME}
PORTDATA=	*

post-patch:
# Search assets under PREFIX instead of current directory
	@${REINPLACE_CMD} '/_dir/s,"\.,"${DATADIR},' ${WRKSRC}/src/main.rs

post-install:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "assets mods" ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
