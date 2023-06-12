PORTNAME=	at-spi2-atk
PORTVERSION=	2.38.0
DISTVERSIONSUFFIX=	-4.el9
CATEGORIES=	accessibility linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Assistive technology ATK bridge (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://gitlab.gnome.org/GNOME/at-spi2-atk

LICENSE=	LGPL20+

USES=		cpe linux:rl9
USE_LDCONFIG=	yes
USE_LINUX=	at-spi2-core atk dbuslibs
USE_LINUX_RPM=	yes
CPE_VENDOR=	gnome

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
