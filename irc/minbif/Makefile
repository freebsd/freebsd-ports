# Created by: Frank Steinborn <steinex@nognu.de>
# $FreeBSD$

PORTNAME=	minbif
PORTVERSION=	1.0.5
PORTREVISION=	6
CATEGORIES=	irc net-im
MASTER_SITES=	https://symlink.me/attachments/download/148/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IRC to instant messaging gateway

LICENSE=	GPLv2

LIB_DEPENDS=	libpurple.so:${PORTSDIR}/net-im/libpurple

# right now PLUGINS installs prpl-coincoin and prpl-gayattitude
OPTIONS_DEFINE=	CACA GNUTLS VIDEO PLUGINS DOCS
OPTIONS_DEFAULT=	CACA
CACA_DESC=	Buddy icon display using libcaca
VIDEO_DESC=	Webcam display using libcaca (depends on CACA)
PLUGINS_DESC=	Compile additional libpurple-plugins

USE_RC_SUBR=	minbif

USES=		cmake pkgconfig
USE_GNOME=	glib20

CFLAGS+=	-DX_DISPLAY_MISSING
LDFLAGS+=	-pthread

USERS=		minbif
GROUPS=		minbif

SUB_FILES=	pkg-message
SUB_LIST=	USERS="${USERS}"

PORTDOCS=	*
PLIST_FILES=	bin/minbif %%ETCDIR%%/minbif.conf-dist \
		%%ETCDIR%%/minbif.motd-dist man/man8/minbif.8.gz
PLIST_DIRS=	%%ETCDIR%%

CACA_LIB_DEPENDS=	libcaca.so:${PORTSDIR}/graphics/libcaca
CACA_CMAKE_ON=		-DENABLE_CACA:BOOL=ON -DENABLE_IMLIB:BOOL=ON
CACA_CMAKE_OFF=		-DENABLE_CACA:BOOL=OFF -DENABLE_IMLIB:BOOL=OFF

GNUTLS_LIB_DEPENDS=	libgnutls.so:${PORTSDIR}/security/gnutls
GNUTLS_CMAKE_ON=	-DENABLE_TLS:BOOL=ON
GNUTLS_CMAKE_OFF=	-DENABLE_TLS:BOOL=OFF

PLUGINS_USE=		GNOME=libxml2
PLUGINS_CMAKE_ON=	-DENABLE_PLUGIN:BOOL=ON
PLUGINS_CMAKE_OFF=	-DENABLE_PLUGIN:BOOL=OFF
PLUGINS_PLIST_FILES=	lib/purple-2/libcoincoin.so \
			lib/purple-2/libgayattitude.so

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MVIDEO} && !empty(PORT_OPTIONS:MCACA)
USE_GSTREAMER+=	core good
LIB_DEPENDS+=	libgstfarsight-0.10.so:${PORTSDIR}/net-im/farsight2
CMAKE_ARGS+=	-DENABLE_VIDEO:BOOL=ON
.else
CMAKE_ARGS+=	-DENABLE_VIDEO:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MCACA}
USE_EFL=	imlib2
.endif

.if ${PORT_OPTIONS:MVIDEO} && empty(PORT_OPTIONS:MCACA)
IGNORE=	if you want to enable webcam support, you must also enable CACA
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|"-lpthread -lstdc++"||' ${WRKSRC}/src/CMakeLists.txt
	@${REINPLACE_CMD} -e \
		'/pam_misc.h/d' ${WRKSRC}/src/im/auth_pam.h

post-build:
	@${LN} -sf minbif.conf ${WRKSRC}/minbif.conf-dist
	@${LN} -sf minbif.motd ${WRKSRC}/minbif.motd-dist

do-install:
	(cd ${WRKSRC}/src && ${INSTALL_PROGRAM} ${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC}/man && ${INSTALL_MAN} minbif.8 \
		${STAGEDIR}${MAN8PREFIX}/man/man8)
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} minbif.conf-dist \
		${STAGEDIR}${ETCDIR})
	(cd ${WRKSRC} && ${INSTALL_DATA} minbif.motd-dist \
		${STAGEDIR}${ETCDIR})
.if ${PORT_OPTIONS:MPLUGINS}
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/purple-2
	(cd ${WRKSRC}/plugins/coincoin && ${INSTALL_LIB} libcoincoin.so \
		${STAGEDIR}${PREFIX}/lib/purple-2)
	(cd ${WRKSRC}/plugins/gayattitude && ${INSTALL_LIB} libgayattitude.so \
		${STAGEDIR}${PREFIX}/lib/purple-2)
.endif
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} README \
		${STAGEDIR}${DOCSDIR})
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} minbif.xinetd \
		${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
