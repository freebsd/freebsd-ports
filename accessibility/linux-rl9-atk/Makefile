PORTNAME=	atk
PORTVERSION=	2.36.0
DISTVERSIONSUFFIX=	-5.el9
CATEGORIES=	accessibility linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Accessibility Toolkit (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://developer.gnome.org/atk/

LICENSE=	GPLv3

USES=		linux:rl9
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes

CONFLICTS=	linux-c7-${PORTNAME}

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

.include <bsd.port.mk>
