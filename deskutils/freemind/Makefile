# Created by: cartola (Carlos E. G. Carvalho)
# $FreeBSD$

PORTNAME=	freemind
PORTVERSION=	1.0.1
PORTEPOCH=	1
CATEGORIES=	deskutils editors java
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-bin-max-${PORTVERSION}

MAINTAINER=	sergey.v.brunov@gmail.com
COMMENT=	Free mind-mapping software written in Java

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/license

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip \
		zip:${PORTSDIR}/archivers/zip

USES=		cpe zip:infozip
USE_JAVA=	yes
JAVA_VERSION=	1.6+

DATADIR=	${JAVASHAREDIR}/${PORTNAME}-${PORTVERSION}
DATAFILES=	accessories browser doc lib plugins patterns.xml

EXTRACT_AFTER_ARGS=	-d ${WRKSRC}
ZIP_CMD=	zip

SUB_FILES=	freemind.sh

do-build:
	(cd ${WRKSRC}; \
	${UNZIP_CMD} lib/freemind.jar freemind.properties; \
	${REINPLACE_CMD} -e '/^keystroke_node_increase_font_size/ s/PLUS/EQUALS/;/^keystroke_branch_increase_font_size/ s/PLUS/EQUALS/;s|./doc/freemind.mm|file:${DATADIR}/doc/freemind.mm|' freemind.properties; \
	${ZIP_CMD} -u lib/freemind.jar freemind.properties)

do-install:
	cd ${WRKSRC} \
	  && ${FIND} ${DATAFILES} -type d -exec ${MKDIR} ${STAGEDIR}${DATADIR}/{} \; \
	  && ${FIND} ${DATAFILES} -type f -exec ${INSTALL_DATA} {} ${STAGEDIR}${DATADIR}/{} \;
	${INSTALL_SCRIPT} ${WRKDIR}/freemind.sh ${STAGEDIR}${PREFIX}/bin/freemind

.include <bsd.port.mk>
