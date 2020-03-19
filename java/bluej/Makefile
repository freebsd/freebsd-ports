# Created by: Jeremy <karlj000@unbc.ca>
# $FreeBSD$

PORTNAME=	bluej
PORTVERSION=	4.1.1
CATEGORIES=	java editors
MASTER_SITES=	http://www.bluej.org/download/files/
DISTNAME=	BlueJ-generic-${PORTVERSION:S/.//g}
EXTRACT_SUFX=	.jar

MAINTAINER=	woodsb02@FreeBSD.org
COMMENT=	Integrated Java environment designed for introductory teaching

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

DEPRECATED=	depends on expiring java/openjfx8-devel
EXPIRATION_DATE=	2020-11-30

RUN_DEPENDS=	${JAVA_HOME}/bin/javafxpackager:java/openjfx8-devel

NO_ARCH=	yes
NO_BUILD=	yes

USE_JAVA=	yes
JAVA_VERSION=	1.8+
SUB_FILES=	bluej
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
