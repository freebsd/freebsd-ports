# New ports collection makefile for:	minbif
# Date created:				2010-06-03
# Whom:					Frank Steinborn <steinex@nognu.de>
#
# $FreeBSD$
#

PORTNAME=	minbif
PORTVERSION=	1.0.1
CATEGORIES=	irc net-im
MASTER_SITES=	http://symlink.me/attachments/download/39/

MAINTAINER=	steinex@nognu.de
COMMENT=	An IRC to instant messaging gateway

LIB_DEPENDS=	purple.6:${PORTSDIR}/net-im/libpurple

USERS=		minbif
GROUPS=		minbif

SUB_FILES=	pkg-message
MAN8=		minbif.8

PLIST_FILES=	bin/minbif %%ETCDIR%%/minbif.conf-dist \
		%%ETCDIR%%/minbif.motd-dist
PLIST_DIRS=	%%ETCDIR%%

USE_CMAKE=	yes
USE_RC_SUBR=	minbif
PKGMESSAGE=	${WRKDIR}/pkg-message
PORTDOCS=	*

# right now WITH_PLUGINS installs prpl-coincoin and prpl-gayattitude
OPTIONS=	CACA "Buddy icon display using libcaca" On \
		VIDEO "Webcam display using libcaca (depends on CACA)" Off \
		PLUGINS "Compile additional libpurple-plugins" Off

SUB_LIST+=	USERS=${USERS}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=		does not link on 6.X
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-Werror||g' ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|-Wall||g' ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e \
		's|message.c_str(), NULL);|message.c_str(), (char*)NULL);|g' \
		${WRKSRC}/src/im/account.cpp
	@${REINPLACE_CMD} -e \
		's|#include <libpurple/purple.h>|#include <purple.h>|g' \
		${WRKSRC}/src/core/callback.h ${WRKSRC}/src/core/minbif.cpp \
		${WRKSRC}/src/core/util.h ${WRKSRC}/src/im/account.h \
		${WRKSRC}/src/im/buddy.h ${WRKSRC}/src/im/conversation.h \
		${WRKSRC}/src/im/ft.h ${WRKSRC}/src/im/media.h \
		${WRKSRC}/src/im/protocol.h ${WRKSRC}/src/im/purple.cpp \
		${WRKSRC}/src/im/request.h ${WRKSRC}/src/im/roomlist.h \
		${WRKSRC}/src/irc/nick.h

.include <bsd.port.options.mk>

.if defined(WITH_CACA)
LIB_DEPENDS+=	caca.0:${PORTSDIR}/graphics/libcaca
CMAKE_ARGS+=	-DENABLE_CACA:BOOL=ON
.else
CMAKE_ARGS+=	-DENABLE_CACA:BOOL=OFF
.endif

.if defined(WITH_VIDEO) && defined(WITH_CACA)
USE_GSTREAMER+=	core good
LIB_DEPENDS+=	gstfarsight-0.10.0:${PORTSDIR}/net-im/farsight2
CMAKE_ARGS+=	-DENABLE_VIDEO:BOOL=ON
.else
CMAKE_ARGS+=	-DENABLE_VIDEO:BOOL=OFF
.endif

.if defined(WITH_VIDEO) && !defined(WITH_CACA)
IGNORE=		if you want to enable webcam support, you must \
		also enable CACA.
.endif

.if defined(WITH_PLUGINS)
CMAKE_ARGS+=	-DENABLE_PLUGIN:BOOL=ON
PLIST_FILES+=	lib/purple-2/libcoincoin.so \
		lib/purple-2/libgayattitude.so
.else
CMAKE_ARGS+=	-DENABLE_PLUGIN:BOOL=OFF
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/minbif.8 ${MAN8PREFIX}/man/man8
	${MKDIR} ${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/minbif.conf ${ETCDIR}/minbif.conf-dist
	${INSTALL_DATA} ${WRKSRC}/minbif.motd ${ETCDIR}/minbif.motd-dist
.if defined(WITH_PLUGINS)
	${INSTALL_PROGRAM} ${WRKSRC}/plugins/coincoin/libcoincoin.so ${PREFIX}/lib/purple-2
	${INSTALL_PROGRAM} ${WRKSRC}/plugins/gayattitude/libgayattitude.so ${PREFIX}/lib/purple-2
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/minbif.xinetd ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
