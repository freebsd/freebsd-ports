# New ports collection makefile for:	openlierox
# Date created:		12 Oct 2008
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	openlierox
DISTVERSION=	0.57_beta8
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/OpenLieroX%200.57%20Beta8
DISTNAME=	OpenLieroX_${DISTVERSION}.src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Extremely addictive realtime worms shoot-em-up

LIB_DEPENDS=	gd.4:${PORTSDIR}/graphics/gd

USE_BZIP2=	yes
USE_SDL=	sdl image
USE_GNOME=	libxml2

CFLAGS+=	-I${LOCALBASE}/include/libxml2
CXXFLAGS+=	-I${LOCALBASE}/include/libxml2

USE_CMAKE=	yes
CMAKE_ARGS=	-DHAWKNL_BUILTIN=YES \
		-DLIBZIP_BUILTIN=YES

WRKSRC=		${WRKDIR}/OpenLieroX

PORTDOCS=	*

OPTIONS=	DEDICATED_ONLY "Build dedicated server only" off

.include <bsd.port.pre.mk>

.if defined(WITH_DEDICATED_ONLY)
CMAKE_ARGS+=	-DDEDICATED_ONLY=YES
.else
USE_XORG+=	x11
USE_SDL+=	mixer
.endif

post-extract:
	@${FIND} ${WRKSRC} -name "._*" -delete
	@cd ${WRKSRC} && ${MKDIR} bin

post-patch:
	@${REINPLACE_CMD} -e 's|sys/dir.h|dirent.h|' \
		${WRKSRC}/src/main.cpp ${WRKSRC}/include/FindFile.h
	@${REINPLACE_CMD} -e 's|DATADIR|"${DATADIR}"|' \
		${WRKSRC}/src/main.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/openlierox ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	cd ${WRKSRC}/share/gamedir && ${COPYTREE_SHARE} . ${DATADIR}
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/share/openlierox-openlierox.desktop \
		${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/share/OpenLieroX.svg \
		${PREFIX}/share/pixmaps

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
