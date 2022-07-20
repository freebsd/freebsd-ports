PORTNAME=	bluej
PORTVERSION=	4.2.2
CATEGORIES=	java editors
MASTER_SITES=	http://www.bluej.org/download/files/
DISTNAME=	BlueJ-generic-${PORTVERSION:S/.//g}
EXTRACT_SUFX=	.jar

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Integrated Java environment designed for introductory teaching

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	openjfx14>0:java/openjfx14

NO_ARCH=	yes
NO_BUILD=	yes

USE_JAVA=	yes
JAVA_VERSION=	11+
SUB_FILES=	bluej
SUB_LIST=	JAVA_HOME=${JAVA_HOME}
DATADIR=	${JAVASHAREDIR}/${PORTNAME}

DESKTOP_ENTRIES="BlueJ" \
		"${COMMENT}" \
		"${DATADIR}/icons/bluej-icon-512-embossed.png" \
		"bluej" \
		"Application;Development;" \
		true

post-extract:
	@${MKDIR} ${WRKSRC}
	@${TAR} -xf ${WRKDIR}/bluej-dist.jar -C ${WRKSRC}

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}; ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/bluej ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
