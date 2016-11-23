# Created by: Piotr Smyrak <smyru@heron.pl>
# $FreeBSD$

PORTNAME=	agave
PORTVERSION=	0.4.7
PORTREVISION=	2
CATEGORIES=	graphics gnome
MASTER_SITES=	http://download.gna.org/colorscheme/releases/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Color scheme builder for the GNOME desktop

LICENSE=	GPLv2+

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		libglademm-2.4.so:devel/libglademm24

USES=		gettext gmake pathfix pkgconfig tar:bzip2
USE_GNOME=	gconfmm26 gnomedocutils gnomeprefix gtkmm24 intltool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-scrollkeeper \
		--disable-schemas-install \
		--disable-cppunit
INSTALLS_ICONS=	yes
INSTALLS_OMF=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GCONF_SCHEMAS=	agave.schemas

OPTIONS_DEFINE=		GNOME

GNOME_USE=		gnome=libgnomeui
GNOME_CONFIGURE_ENABLE=	gnome

post-patch:
	@${REINPLACE_CMD} -e \
		's| _GCS_| __GCS_|' ${WRKSRC}/src/gcs-conf.h

.include <bsd.port.mk>
