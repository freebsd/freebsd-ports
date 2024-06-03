PORTNAME=	resid
PORTVERSION=	0.16
PORTREVISION=	4
CATEGORIES=	audio emulators
MASTER_SITES=	LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Cycle-based SID emulator engine

LICENSE=	GPLv2

DEPRECATED=	Upstream recommends using emulators/vice instead
EXPIRATION_DATE=2024-09-03

USES=		libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CONFIGURE_ARGS=		--enable-shared

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
