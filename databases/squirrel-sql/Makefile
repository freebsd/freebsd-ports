# Created by: Roy Boerner

PORTNAME=	squirrel-sql
PORTVERSION=	4.4.0
CATEGORIES=	databases java
MASTER_SITES=	SF/${PORTNAME}/1-stable/${PORTVERSION}-plainzip
DISTNAME=	squirrelsql-${PORTVERSION}-optional

MAINTAINER=	jonc@chen.org.nz
COMMENT=	Universal SQL Client

LICENSE=	GPLv2

USES=		zip
USE_JAVA=	11+

DATADIR=	${PREFIX}/share/java/${PKGBASE}

DESKTOP_ENTRIES="Squirrel-SQL Client" \
		"${COMMENT}" \
		"${DATADIR}/icons/acorn.png" \
		"squirrel-sql" \
		"Development;Database;Java;" \
		false
NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	squirrel-sql

WRKSRC=		${WRKDIR}/${DISTNAME}

post-extract:
	cd "${WRKSRC}" && ${RM} -r *.bat *.sh icons/acorn.png.bak.png mac squirrelcli

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd "${WRKSRC}" && ${FIND} . | ${CPIO} -pdum -R root:wheel ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/squirrel-sql ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
