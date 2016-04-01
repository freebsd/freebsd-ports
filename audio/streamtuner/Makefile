# Created by: Jean-Yves Lefort <jylefort@brutele.be>
# $FreeBSD$

PORTNAME=	streamtuner
PORTVERSION=	0.99.99
PORTREVISION=	21
CATEGORIES=	audio www
MASTER_SITES=	SAVANNAH

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK+ stream directory browser

BROKEN=		Is no longer able to fetch stream information

BUILD_DEPENDS=	rarian-sk-config:textproc/rarian
LIB_DEPENDS=	libcurl.so:ftp/curl
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gnome-icon-theme.pc:misc/gnome-icon-theme

USES=		gettext gmake libtool pathfix pkgconfig
USE_GNOME=	gtk20 gnomeprefix
INSTALLS_OMF=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	SHOUTCAST LIVE365 XIPH LOCAL LOCAL_METADATA PYTHON
OPTIONS_DEFAULT=	SHOUTCAST LIVE365 XIPH LOCAL LOCAL_METADATA
SHOUTCAST_DESC=	SHOUTcast plugin
LIVE365_DESC=	Live365 plugin
LOCAL_DESC=	Local plugin
LOCAL_METADATA_DESC=	Metadata support for the Local plugin
XIPH_DESC=	Xiph plugin

OPTIONS_SUB=	yes
SHOUTCAST_CONFIGURE_ENABLE=	shoutcast
LIB365_CONFIGURE_ENABLE=	libve365
XIPH_CONFIGURE_ENABLE=	xiph
PYTHON_USE=	gnome=pygtk2
PYTHON_USES=	python
PYTHON_CONFIGURE_ENABLE=	python

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLOCAL}
PLIST_SUB+=	LOCAL=""
.if ${PORT_OPTIONS:MLOCAL_METADATA}
LIB_DEPENDS+=	libtag_c.so:audio/taglib
.else
CONFIGURE_ARGS+=	--disable-local-metadata
.endif
.else
CONFIGURE_ARGS+=	--disable-local
PLIST_SUB+=	LOCAL="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|[(]datadir[)]/help|(datadir)/gnome/help|g' \
		${WRKSRC}/help/C/Makefile.in

.include <bsd.port.mk>
