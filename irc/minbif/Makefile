# Created by: Frank Steinborn <steinex@nognu.de>
# $FreeBSD$

PORTNAME=	minbif
PORTVERSION=	1.0.5
PORTREVISION=	1
CATEGORIES=	irc net-im
MASTER_SITES=	https://symlink.me/attachments/download/148/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An IRC to instant messaging gateway

LICENSE=	GPLv2

LIB_DEPENDS=	purple:${PORTSDIR}/net-im/libpurple

# right now PLUGINS installs prpl-coincoin and prpl-gayattitude
OPTIONS_DEFINE=	CACA GNUTLS VIDEO PLUGINS DOCS
OPTIONS_DEFAULT=	CACA
CACA_DESC=	Buddy icon display using libcaca
VIDEO_DESC=	Webcam display using libcaca (depends on CACA)
PLUGINS_DESC=	Compile additional libpurple-plugins

USE_RC_SUBR=	minbif
USE_GNOME=	glib20
USE_EFL=	imlib2
USE_CMAKE=	yes
CMAKE_ARGS=	-DENABLE_IMLIB:BOOL=ON
MAKE_JOBS_SAFE=	yes

CFLAGS+=	${PTHREAD_CFLAGS} -DX_DISPLAY_MISSING
LDFLAGS+=	${PTHREAD_LIBS}

USERS=		minbif
GROUPS=		minbif

SUB_FILES=	pkg-message
SUB_LIST=	USERS="${USERS}"

MAN8=		minbif.8
PORTDOCS=	*
PLIST_FILES=	bin/minbif %%ETCDIR%%/minbif.conf-dist \
		%%ETCDIR%%/minbif.motd-dist
PLIST_DIRS=	%%ETCDIR%%

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCACA}
LIB_DEPENDS+=	caca:${PORTSDIR}/graphics/libcaca
CMAKE_ARGS+=	-DENABLE_CACA:BOOL=ON
.else
CMAKE_ARGS+=	-DENABLE_CACA:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MVIDEO} && !empty(PORT_OPTIONS:MCACA)
USE_GSTREAMER+=	core good
LIB_DEPENDS+=	gstfarsight-0.10:${PORTSDIR}/net-im/farsight2
CMAKE_ARGS+=	-DENABLE_VIDEO:BOOL=ON
.else
CMAKE_ARGS+=	-DENABLE_VIDEO:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MVIDEO} && empty(PORT_OPTIONS:MCACA)
IGNORE=		if you want to enable webcam support, you must \
		also enable CACA.
.endif

.if ${PORT_OPTIONS:MPLUGINS}
USE_GNOME+=	libxml2
CMAKE_ARGS+=	-DENABLE_PLUGIN:BOOL=ON
PLIST_FILES+=	lib/purple-2/libcoincoin.so \
		lib/purple-2/libgayattitude.so
.else
CMAKE_ARGS+=	-DENABLE_PLUGIN:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MGNUTLS}
LIB_DEPENDS+=	gnutls:${PORTSDIR}/security/gnutls
CMAKE_ARGS+=	-DENABLE_TLS:BOOL=ON
.else
CMAKE_ARGS+=	-DENABLE_TLS:BOOL=OFF
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|"-lpthread -lstdc++"||' ${WRKSRC}/src/CMakeLists.txt
	@${REINPLACE_CMD} -e \
		'/pam_misc.h/d' ${WRKSRC}/src/im/auth_pam.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/minbif.8 ${MAN8PREFIX}/man/man8
	${MKDIR} ${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/minbif.conf ${ETCDIR}/minbif.conf-dist
	${INSTALL_DATA} ${WRKSRC}/minbif.motd ${ETCDIR}/minbif.motd-dist
.if ${PORT_OPTIONS:MPLUGINS}
	${INSTALL_PROGRAM} ${WRKSRC}/plugins/coincoin/libcoincoin.so ${PREFIX}/lib/purple-2
	${INSTALL_PROGRAM} ${WRKSRC}/plugins/gayattitude/libgayattitude.so ${PREFIX}/lib/purple-2
.endif
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/minbif.xinetd ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
