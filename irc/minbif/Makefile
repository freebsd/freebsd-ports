# Created by: Frank Steinborn <steinex@nognu.de>
# $FreeBSD$

PORTNAME=	minbif
PORTVERSION=	1.0.5
PORTREVISION=	10
CATEGORIES=	irc net-im
MASTER_SITES=	https://symlink.me/attachments/download/148/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IRC to instant messaging gateway

LICENSE=	GPLv2

LIB_DEPENDS=	libpurple.so:net-im/libpurple

USES=		cmake:insource pkgconfig
USE_GNOME=	glib20
USE_RC_SUBR=	${PORTNAME}

CFLAGS+=	-DX_DISPLAY_MISSING
LDFLAGS+=	-pthread

USERS=		minbif
GROUPS=		minbif

SUB_FILES=	pkg-message
SUB_LIST=	USERS="${USERS}"

OPTIONS_DEFINE=	CACA GNUTLS VIDEO PLUGINS DOCS
OPTIONS_DEFAULT=	CACA
VIDEO_IMPLIES=	CACA

CACA_DESC=	Buddy icon display using libcaca
VIDEO_DESC=	Webcam display using libcaca (implies CACA)
PLUGINS_DESC=	Compile additional libpurple-plugins

CACA_LIB_DEPENDS=	libcaca.so:graphics/libcaca \
			libImlib2.so:graphics/imlib2
CACA_CMAKE_BOOL=	ENABLE_CACA ENABLE_IMLIB

GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
GNUTLS_CMAKE_BOOL=	ENABLE_TLS

PLUGINS_USE=		GNOME=libxml2
PLUGINS_CMAKE_BOOL=	ENABLE_PLUGIN
PLUGINS_PLIST_FILES=	lib/purple-2/libcoincoin.so \
			lib/purple-2/libgayattitude.so

VIDEO_USE=		GSTREAMER=core,good
VIDEO_CMAKE_BOOL=	ENABLE_VIDEO
VIDEO_LIB_DEPENDS=	libgstfarsight-0.10.so:net-im/farsight2

post-patch:
	@${REINPLACE_CMD} -e \
		's|"-lpthread -lstdc++"||' ${WRKSRC}/src/CMakeLists.txt
	@${REINPLACE_CMD} -e '/pam_misc\.h/d' ${WRKSRC}/src/im/auth_pam.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/minbif.8 ${STAGEDIR}${MANPREFIX}/man/man8
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/minbif.conf \
		${STAGEDIR}${ETCDIR}/minbif.conf.sample
	${INSTALL_DATA} ${WRKSRC}/minbif.motd \
		${STAGEDIR}${ETCDIR}/minbif.motd.sample

do-install-PLUGINS-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/purple-2
	${INSTALL_LIB} ${WRKSRC}/plugins/coincoin/libcoincoin.so \
		${WRKSRC}/plugins/gayattitude/libgayattitude.so \
			${STAGEDIR}${PREFIX}/lib/purple-2

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in AUTHORS ChangeLog README doc/minbif.xinetd
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
