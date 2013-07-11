# Created by: Jean-Yves Lefort <jylefort@brutele.be>
# $FreeBSD$

PORTNAME=	streamtuner
PORTVERSION=	0.99.99
PORTREVISION=	20
CATEGORIES=	audio www
MASTER_SITES=	SAVANNAH
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK+ stream directory browser

BUILD_DEPENDS=	rarian-sk-config:${PORTSDIR}/textproc/rarian
LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gnome-icon-theme.pc:${PORTSDIR}/misc/gnome-icon-theme

USES=        pathfix
USE_GNOME=	gtk20 gnomeprefix
USE_GMAKE=	yes
INSTALLS_OMF=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	SHOUTCAST LIVE365 XIPH LOCAL LOCAL_METADATA
OPTIONS_DEFAULT=	SHOUTCAST LIVE365 XIPH LOCAL LOCAL_METADATA
SHOUTCAST_DESC=	SHOUTcast plugin
LIVE365_DESC=	Live365 plugin
LOCAL_DESC=	Local plugin
LOCAL_METADATA_DESC=	Metadata support for the Local plugin
XIPH_DESC=	Xiph plugin

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSHOUTCAST}
PLIST_SUB+=	SHOUTCAST=""
.else
CONFIGURE_ARGS+=	--disable-shoutcast
PLIST_SUB+=	SHOUTCAST="@comment "
.endif

.if ${PORT_OPTIONS:MLIVE365}
PLIST_SUB+=	LIVE365=""
.else
CONFIGURE_ARGS+=	--disable-live365
PLIST_SUB+=	LIVE365="@comment "
.endif

.if ${PORT_OPTIONS:MXIPH}
PLIST_SUB+=	XIPH=""
USE_GNOME+=	libxml2
.else
CONFIGURE_ARGS+=	--disable-xiph
PLIST_SUB+=	XIPH="@comment "
.endif

.if ${PORT_OPTIONS:MLOCAL}
PLIST_SUB+=	LOCAL=""
.if ${PORT_OPTIONS:MLOCAL_METADATA}
LIB_DEPENDS+=	tag_c:${PORTSDIR}/audio/taglib
.else
CONFIGURE_ARGS+=	--disable-local-metadata
.endif
.else
CONFIGURE_ARGS+=	--disable-local
PLIST_SUB+=	LOCAL="@comment "
.endif

.if ${PORT_OPTIONS:MPYTHON}
PLIST_SUB+=	PYTHON=""
USE_PYTHON=	2.5+
# we need to manually include this, because USE_PYTHON is defined
# after including bsd.port.pre.mk
.include "${PORTSDIR}/Mk/bsd.python.mk"
USE_GNOME+=	pygtk2
.else
CONFIGURE_ARGS+=	--disable-python
PLIST_SUB+=	PYTHON="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|[(]datadir[)]/help|(datadir)/gnome/help|g' \
		${WRKSRC}/help/C/Makefile.in

.include <bsd.port.mk>
