# Created by: Roy Boerner
# $FreeBSD$

PORTNAME=	squirrel-sql
PORTVERSION=	3.5.1
CATEGORIES=	databases java
MASTER_SITES=	SF/${PORTNAME}/1-stable/${PORTVERSION}-plainzip
DISTNAME=	squirrelsql-plainzip-${PORTVERSION}-optional

MAINTAINER=	jonc@chen.org.nz
COMMENT=	Universal SQL Client

LICENSE=	GPLv2

NO_BUILD=	yes
USES=		zip
USE_JAVA=	yes
JAVA_VERSION=	1.6+
WRKSRC=		${WRKDIR}/${DISTNAME}

SUB_FILES=	squirrel-sql

DATADIR=	${PREFIX}/share/java/${UNIQUENAME}

DESKTOP_ENTRIES="Squirrel-SQL Client" \
		"${COMMENT}" \
		"${DATADIR}/icons/acorn.png" \
		"squirrel-sql" \
		"Development;Database;Java;" \
		false

post-extract:
	cd "${WRKSRC}" && ${RM} -rf Uninstaller *.bat *.sh .installationinformation

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd "${WRKSRC}" && ${FIND} . | ${CPIO} -pdum -R root:wheel ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/squirrel-sql ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
