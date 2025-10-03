PORTNAME=	uhubctl
DISTVERSION=	2.6.0
CATEGORIES=	comms devel sysutils

MAINTAINER=	tomek@cedro.info
COMMENT=	Utility to control USB power per-port on smart USB hubs
WWW=		https://github.com/mvp/uhubctl

LICENSE=	GPLv2
LICENSE_FILE	=${WRKSRC}/LICENSE

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	mvp
GH_TAGNAME=	v2.6.0

ALL_TARGET=	uhubctl

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/uhubctl ${STAGEDIR}${PREFIX}/sbin

.include <bsd.port.mk>
