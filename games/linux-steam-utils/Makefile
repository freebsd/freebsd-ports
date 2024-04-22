PORTNAME=	steam-utils
DISTVERSION=	20240323
CATEGORIES=	games linux
PKGNAMEPREFIX=	linux-

MAINTAINER=	iwtcex@gmail.com
COMMENT=	Steam launcher for FreeBSD
WWW=		https://github.com/shkhln/linuxulator-steam-utils

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64

RUN_DEPENDS=	ca_root_nss>=0:security/ca_root_nss \
		gtar:archivers/gtar \
		liberation-fonts-ttf>=0:x11-fonts/liberation-fonts-ttf \
		zenity:x11/zenity

USES=		linux ruby:run

USE_GITHUB=	yes
GH_ACCOUNT=	shkhln
GH_PROJECT=	linuxulator-steam-utils

USE_LINUX=	devtools:build dbuslibs gtk2 dri nss alsa-plugins-oss

MAKE_ARGS+=	PREFIX=${STAGEDIR}${PREFIX}
ALL_TARGET=	build

PORTSCOUT=	ignore:1

SUB_FILES=	pkg-message

.include <bsd.port.options.mk>

post-install:
	${LN} -s ../steam-utils/bin/steam         ${STAGEDIR}${PREFIX}/bin/steam
	${LN} -s ../steam-utils/bin/lsu-bootstrap ${STAGEDIR}${PREFIX}/bin/steam-install # deprecated since 2024-03-23
	${LN} -s ../steam-utils/bin/lsu-wine-env  ${STAGEDIR}${PREFIX}/bin/lsu-wine-env

.include <bsd.port.mk>
