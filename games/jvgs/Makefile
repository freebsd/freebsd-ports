PORTNAME=	jvgs
PORTVERSION=	0.5.1
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-${PORTVERSION:C/\.[0-9]+$//}
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Minimalistic platform game

# Converted from NO_CDROM
LICENSE=	jvgs
LICENSE_NAME=	jvgs
LICENSE_TEXT=	contains data under CC-by-NC-SA
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

BUILD_DEPENDS=	swig:devel/swig
LIB_DEPENDS=	libfreetype.so:print/freetype2

USES=		cmake:insource gl lua:51 sdl
USE_SDL=	sdl mixer
USE_GL=		gl glu

SUB_FILES=	${PORTNAME}

PLIST_FILES=	bin/${PORTNAME} libexec/${PORTNAME}
PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|main.lua|${DATADIR}/&|' ${WRKSRC}/src/main.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/jvgs ${STAGEDIR}${PREFIX}/libexec/
	${INSTALL_SCRIPT} ${WRKDIR}/jvgs ${STAGEDIR}${PREFIX}/bin/
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "resources main.lua" ${STAGEDIR}${DATADIR}/

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
