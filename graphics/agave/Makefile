# New ports collection makefile for:	gnome-colorscheme
# Date created:				30 August 2005
# Whom:					Piotr Smyrak <smyru@heron.pl>
#
# $FreeBSD$
#

PORTNAME=	colorscheme
PORTVERSION=	0.3.91
CATEGORIES=	graphics gnome
MASTER_SITES=	http://download.gna.org/${PORTNAME}/releases/
PKGNAMEPREFIX=	gnome-

MAINTAINER=	smyru@heron.pl
COMMENT=	A color scheme builder for the GNOME desktop

LIB_DEPENDS=	gtkmm-2.4.1:${PORTSDIR}/x11-toolkits/gtkmm24 \
		gconfmm-2.6:${PORTSDIR}/devel/gconfmm26 \
		boost_thread.3:${PORTSDIR}/devel/boost

OPTIONS=	GNOME	"Adds GNOME support"	on

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack libgnomeui
GNU_CONFIGURE=	yes
USE_GCC=	3.4+
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if defined(WITHOUT_GNOME)
CONFIGURE_ARGS+=	--disable-gnome --disable-gconf
.endif

.include <bsd.port.post.mk>
