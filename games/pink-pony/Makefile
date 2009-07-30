# New ports collection makefile for:	pink-pony
# Date created:		07 Jul 2009
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pink-pony
PORTVERSION=	1.1
CATEGORIES=	games
MASTER_SITES=	GOOGLE_CODE \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Tron-like multiplayer racing game

LIB_DEPENDS=	IL.2:${PORTSDIR}/graphics/devil \
		protobuf.4:${PORTSDIR}/devel/protobuf \
		glfw.0:${PORTSDIR}/graphics/glfw \
		Half.6:${PORTSDIR}/graphics/ilmbase
BUILD_DEPENDS=	${LOCALBASE}/lib/libaudiere.so:${PORTSDIR}/audio/audiere
RUN_DEPENDS=	${LOCALBASE}/lib/libaudiere.so:${PORTSDIR}/audio/audiere

USE_BZIP2=	yes
USE_SCONS=	yes
USE_GL=		gl glu
MAKE_JOBS_SAFE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

PORTDOCS=	README

post-patch:
	@${REINPLACE_CMD} -Ee 's,(GLSL|levels|models|music|textures)/,${DATADIR}/&,' \
		${WRKSRC}/pony.options ${WRKSRC}/PinkPony.cc ${WRKSRC}/lib/*.cc
	@${REINPLACE_CMD} -e 's|pony.options|${PREFIX}/etc/pink-pony.conf|' \
		${WRKSRC}/PinkPony.cc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Pony ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/pony.options ${PREFIX}/etc/pink-pony.conf
	cd ${WRKSRC} && ${COPYTREE_SHARE} \
		"GLSL levels models music textures" ${DATADIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/
.endif

.include <bsd.port.mk>
