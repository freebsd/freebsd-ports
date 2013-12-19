# Created by: Piotr Smyrak <smyru@heron.pl>
# $FreeBSD$

PORTNAME=	agave
PORTVERSION=	0.4.2
PORTREVISION=	10
CATEGORIES=	graphics gnome
MASTER_SITES=	http://download.gna.org/colorscheme/releases/

MAINTAINER=	ps.ports@smyrak.com
COMMENT=	A color scheme builder for the GNOME desktop

LIB_DEPENDS=	libglademm-2.4.so:${PORTSDIR}/devel/libglademm24 \
		libboost_thread.so:${PORTSDIR}/devel/boost-libs

# --disable-gnome option is broken in 0.4.2
#OPTIONS=	GNOME	"Adds GNOME support"	on

USE_BZIP2=	yes
USES=		gettext gmake pkgconfig
USE_GNOME=	gnomeprefix gnomehack gnomedocutils intlhack
GCONF_SCHEMAS=	agave.schemas
INSTALLS_ICONS=	yes
INSTALLS_OMF=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

NO_STAGE=	yes
.include <bsd.port.pre.mk>

#.if defined(WITHOUT_GNOME)
#CONFIGURE_ARGS+=	--disable-gnome --disable-gconf
#.else
USE_GNOME+=	libgnomeui
LIB_DEPENDS+=	libgconfmm-2.6.so:${PORTSDIR}/devel/gconfmm26
#.endif

.include <bsd.port.post.mk>
