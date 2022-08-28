PORTNAME=	figtree
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.4-14
DISTVERSIONSUFFIX=	-gf9085b6
CATEGORIES=	biology education java

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Graphical viewer of phylogenetic trees

LICENSE=	GPLv2

USE_JAVA=	yes
USE_ANT=	yes
JAVA_VERSION=	17 # Java 8 fails on aarch64: Internal Error (assembler_aarch64.hpp:237) ...

USE_GITHUB=	yes
GH_ACCOUNT=	rambaut

NO_ARCH=	yes

DESKTOP_ENTRIES="FigTree" "Phylogenetic tree viewer" "${PREFIX}/share/pixmaps/${PORTNAME}.png" "${PORTNAME}" \
		"Biology;Science;Education;" true

PLIST_FILES=	bin/${PORTNAME} \
		${JAVAJARDIR}/${PORTNAME}-pdf.jar \
		${JAVAJARDIR}/${PORTNAME}.jar \
		${JAVAJARDIR}/figtreepanel.jar \
		share/pixmaps/${PORTNAME}.png \

do-install:
	@(echo "#!/bin/sh"; \
	  echo ""; \
	  echo ${JAVA} -jar ${JAVAJARDIR}/${PORTNAME}.jar \
	) > ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${CHMOD} +x ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/dist/*.jar ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/release/Linux/icons/${PORTNAME}.png ${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

.include <bsd.port.mk>
