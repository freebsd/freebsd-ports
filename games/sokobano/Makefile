PORTNAME=	sokobano
DISTVERSION=	1.0.3
CATEGORIES=	games java
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}%20${PORTVERSION}
DISTFILES=	Sokobano.zip

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Entertaining Sokoban game with nice 3D graphics

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/share/java/classes/lwjgl/lwjgl.jar:games/lwjgl
RUN_DEPENDS:=	${LOCALBASE}/share/java/classes/jmf.jar:java/jmf \
		${BUILD_DEPENDS}

USES=		gmake
USE_JAVA=	8
MAKEFILE=	${FILESDIR}/makefile
MAKE_ENV=	JAVA_VERSION=${JAVA_VERSION}
WRKSRC=		${WRKDIR}/Sokobano
BUILD_WRKSRC=	${WRKSRC}/src/gdi1sokoban

JARNAME=	Sokobano-${PORTVERSION}.jar
SUB_FILES=	${PORTNAME}.sh
SUB_LIST=	JARNAME=${JARNAME}

post-extract:
# All levels must be named as ``Level_$id.txt'' (uppercase `L')
	@for f in ${WRKSRC}/res/levelSet/[67]/level_*.txt; do \
		${MV} $$f $${f%le*}L$${f##*/l}; done

do-install:
	${INSTALL_DATA} ${WRKSRC}/bin/Sokobano.jar \
		${STAGEDIR}${JAVAJARDIR}/${JARNAME}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	cd ${WRKSRC}/res && ${COPYTREE_SHARE} "fonts levelSet mesh \
		skins sounds textures" ${STAGEDIR}${DATADIR}/res \
		"! -name highScores.xml"

.include <bsd.port.mk>

PATCH_ARGS+=	-l
