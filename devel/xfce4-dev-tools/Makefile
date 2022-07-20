PORTNAME=	xfce4-dev-tools
PORTVERSION=	4.16.0
CATEGORIES=	devel xfce
MASTER_SITES=	XFCE
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Xfce development tools

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	autoconf>=2.69:devel/autoconf \
		automake>=1.15:devel/automake \
		libtoolize:devel/libtool \
		bash:shells/bash

USES=		gnome pkgconfig shebangfix tar:bzip2 xfce
USE_GNOME=	glib20
SHEBANG_FILES=	helpers/xfce-build helpers/xfce-do-release \
		helpers/xfce-get-translations

GNU_CONFIGURE=	yes

PORTSCOUT=	limitw:1,even

.include <bsd.port.mk>
