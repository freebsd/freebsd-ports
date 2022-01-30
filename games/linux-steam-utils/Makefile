PORTNAME=	steam-utils
DISTVERSION=	20220115
CATEGORIES=	games linux
PKGNAMEPREFIX=	linux-

MAINTAINER=	iwtcex@gmail.com
COMMENT=	Steam launcher for FreeBSD

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64

RUN_DEPENDS=	ca_root_nss>=0:security/ca_root_nss \
		gtar:archivers/gtar \
		liberation-fonts-ttf>=0:x11-fonts/liberation-fonts-ttf \
		zenity:x11/zenity

USES=		linux

USE_GITHUB=	yes
GH_ACCOUNT=	shkhln
GH_PROJECT=	linuxulator-steam-utils

USE_LINUX=	devtools:build dbuslibs gtk2 dri nss alsa-plugins-oss
USE_RUBY=	yes

RUBY_NO_BUILD_DEPENDS=	yes

MAKE_ARGS+=	PREFIX=${STAGEDIR}${PREFIX}
ALL_TARGET=	build

PORTSCOUT=	ignore:1

SUB_FILES=	pkg-message

.include <bsd.port.options.mk>

post-install:
.for executable in steam steam-install lsu-register-proton lsu-wine-env
	${LN} -s ../steam-utils/bin/${executable} ${STAGEDIR}${PREFIX}/bin/${executable}
.endfor

.include <bsd.port.mk>
