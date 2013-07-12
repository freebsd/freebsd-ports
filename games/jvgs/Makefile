# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jvgs
PORTVERSION=	0.5.1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-${PORTVERSION:C/\.[0-9]+$//}
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A minimalistic platform game

BUILD_DEPENDS=	swig:${PORTSDIR}/devel/swig13
LIB_DEPENDS=	freetype:${PORTSDIR}/print/freetype2

USES=		cmake
USE_SDL=	sdl mixer
USE_GL=		gl glu
USE_LUA=	5.1+
MAKE_JOBS_SAFE=	yes

SUB_FILES=	${PORTNAME}

NO_CDROM=	contains data under CC-by-NC-SA

PORTDOCS=	AUTHORS

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|main.lua|${DATADIR}/&|' ${WRKSRC}/src/main.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/jvgs ${PREFIX}/libexec/
	${INSTALL_SCRIPT} ${WRKDIR}/jvgs ${PREFIX}/bin/
	${MKDIR} ${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "resources main.lua" ${DATADIR}/
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${DOCSDIR}
.endif

.include <bsd.port.mk>
