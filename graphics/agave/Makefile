# New ports collection makefile for:	gnome-colorscheme
# Date created:				30 August 2005
# Whom:					Piotr Smyrak <smyru@heron.pl>
#
# $FreeBSD$
#

PORTNAME=	agave
PORTVERSION=	0.4.2
PORTREVISION=	5
CATEGORIES=	graphics gnome
MASTER_SITES=	http://download.gna.org/colorscheme/releases/

MAINTAINER=	smyru@heron.pl
COMMENT=	A color scheme builder for the GNOME desktop

LIB_DEPENDS=	glademm-2.4.1:${PORTSDIR}/devel/libglademm24 \
		boost_thread.4:${PORTSDIR}/devel/boost-libs

# --disable-gnome option is broken in 0.4.2
#OPTIONS=	GNOME	"Adds GNOME support"	on

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gnomedocutils intlhack
GCONF_SCHEMAS=	agave.schemas
INSTALLS_ICONS=	yes
INSTALLS_OMF=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

#.if defined(WITHOUT_GNOME)
#CONFIGURE_ARGS+=	--disable-gnome --disable-gconf
#.else
USE_GNOME+=	libgnomeui
LIB_DEPENDS+=	gconfmm-2.6:${PORTSDIR}/devel/gconfmm26
#.endif

.include <bsd.port.post.mk>
