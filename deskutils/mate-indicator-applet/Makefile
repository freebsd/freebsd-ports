PORTNAME=	mate-indicator-applet
PORTVERSION=	1.26.0
PORTREVISION=	2
CATEGORIES=	deskutils mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Applet to display information from various applications in the panel
WWW=		https://mate-desktop.org/

LICENSE=	GPLv3 LGPL21
LICENSE_COMB=	multi
LICENSE_FILE_GPLv3=	${WRKSRC}/COPYING
LICENSE_FILE_LGPL21=	${WRKSRC}/COPYING.LGPL

BUILD_DEPENDS=	libindicator>=12.10.1:devel/libindicator
RUN_DEPENDS=	mate-applets>=1.22.0:x11/mate-applets \
		libindicator>=12.10.1:devel/libindicator

PORTSCOUT=	limitw:1,even

USES=		compiler:c11 gettext gmake gnome libtool localbase mate \
 		pkgconfig tar:xz
USE_CSTD=	c11

USE_MATE=	panel
USE_GNOME=	gtk30
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
