PORTNAME=	gxneur
PORTVERSION=	0.20.0
PORTREVISION=	2
DISTVERSIONSUFFIX=.orig
CATEGORIES=	deskutils
MASTER_SITES=	https://launchpad.net/~andrew-crew-kuznetsov/+archive/xneur-stable/+files/
DISTNAME=	${PORTNAME}_${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	mizhka@gmail.com
COMMENT=	GTK frontend for XNeur keyboard layout switcher

LICENSE=	GPLv2

BUILD_DEPENDS=	xneur:deskutils/xneur \
		intltool-update:textproc/intltool
RUN_DEPENDS=	xneur:deskutils/xneur

USES=		compiler:c++11-lang pkgconfig gmake gnome
USE_GNOME=	gtk20 libglade2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-gconf

OPTIONS_DEFINE=	NLS

OPTIONS_SUB=	yes
NLS_USES=	gettext
NLS_CONFIGURE_OFF=	--without-nls

.include <bsd.port.mk>
