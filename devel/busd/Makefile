PORTNAME=	busd
DISTVERSION=	0.4.0
PORTREVISION=	7
CATEGORIES=	devel

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	D-Bus daemon/broker implementation based on zbus
WWW=		https://github.com/dbus2/busd

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE-MIT

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	dbus2
PLIST_FILES=	bin/${PORTNAME}

post-patch:
# Respect consolekit2 as XDG_RUNTIME_DIR fallback
	@${REINPLACE_CMD} 's,/run,/var&,' \
		${WRKSRC}/src/bus/mod.rs

.include <bsd.port.mk>
