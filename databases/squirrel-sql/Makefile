# New ports collection makefile for: squirrel-sql
# Date created: 	2006/11/06
# Whom:         	Roy Boerner
#
# $FreeBSD$
#

PORTNAME=	squirrel-sql
PORTVERSION=	3.4.0
CATEGORIES=	databases java
MASTER_SITES=	SF/${PORTNAME}/1-stable/${PORTVERSION}-plainzip
DISTNAME=	${PORTNAME}-${PORTVERSION}-optional

MAINTAINER=	jonc@chen.org.nz
COMMENT=	Universal SQL Client

LICENSE=	GPLv2

NO_BUILD=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.6+
WRKSRC=		${WRKDIR}/${DISTNAME}

SUB_FILES=	squirrel-sql

DATADIR=	${PREFIX}/share/java/${UNIQUENAME}

DESKTOP_ENTRIES="Squirrel-SQL Client" \
		"${COMMENT}" \
		"${DATADIR}/icons/acorn.png" \
		"squirrel-sql" \
		"Office;Database;Java;" \
		false

post-extract:
	cd "${WRKSRC}" && ${RM} -rf Uninstaller *.bat *.sh .installationinformation

do-install:
	${MKDIR} ${DATADIR}
	cd "${WRKSRC}" && ${FIND} . | ${CPIO} -pdum -R root:wheel ${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/squirrel-sql ${PREFIX}/bin
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
