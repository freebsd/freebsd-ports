# New ports collection makefile for: squirrel-sql
# Date created: 	2006/11/06
# Whom:         	Roy Boerner
#
# $FreeBSD$
#

PORTNAME=	squirrel
PORTVERSION=	2.6.4
PORTREVISION=	1
CATEGORIES=	databases java
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	${PORTNAME}${PKGNAMESUFFIX}
PKGNAMESUFFIX=	-sql
DISTNAME=	squirrel-sql-2.6-standard

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A universal SQL Client

NO_BUILD=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.5+
WRKSRC=		${WRKDIR}/SQuirreL SQL Client
DSTDIR=		${JAVASHAREDIR}/${PORTNAME}${PKGNAMESUFFIX}

SUB_FILES=	squirrel-sql
PKGMESSAGE=	pkg-messages

DESKTOP_ENTRIES="Squirrel-SQL Client" \
		"${COMMENT}" \
		"${DSTDIR}/icons/acorn.png" \
		"squirrel-sql" \
		"Application;" \
		false

post-extract:
	${RM} -rf "${WRKSRC}"/Uninstaller
	${RM} -rf "${WRKSRC}"/*.bat
	${RM} -rf "${WRKSRC}"/*.sh

do-install:
	cd "${WRKSRC}" && ${FIND} . -type d -exec ${MKDIR} ${DSTDIR}/{} \;
	cd "${WRKSRC}" && ${FIND} . -type f -not -path "\./bin/" -exec ${INSTALL_DATA} {} ${DSTDIR}/{} \;
	${INSTALL_SCRIPT} ${WRKDIR}/squirrel-sql ${PREFIX}/bin
	@${CAT} ${PKGMESSAGE} 

.include <bsd.port.mk>
