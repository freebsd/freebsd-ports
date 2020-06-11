# $FreeBSD$

PORTNAME=	steam-utils
DISTVERSION=	20200525
CATEGORIES=	games linux
PKGNAMEPREFIX=	linux-

MAINTAINER=	iwtcex@gmail.com
COMMENT=	Steam launcher for FreeBSD

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

IGNORE_FreeBSD_11=not tested at all
ONLY_FOR_ARCHS=	amd64

RUN_DEPENDS=	ca_root_nss>=0:security/ca_root_nss

USES=		linux
USE_LINUX=	devtools:build dbuslibs gtk2 dri nss openal-soft
USE_RUBY=	yes

RUBY_NO_BUILD_DEPENDS=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	shkhln
GH_PROJECT=	linuxulator-steam-utils

ALL_TARGET=	build
MAKE_ARGS+=	PREFIX=${STAGEDIR}${PREFIX}

.include <bsd.port.options.mk>

post-install:
.for executable in steam steam-install
	${LN} -s ../steam-utils/bin/${executable} ${STAGEDIR}${PREFIX}/bin/${executable}
.endfor
.if ${OSVERSION} >= 1300082
	${REINPLACE_CMD} -e '/fmodfix.so/d' ${TMPPLIST}
.endif

.include <bsd.port.mk>
