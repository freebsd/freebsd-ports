# New ports collection makefile for:	viewcvs
# Date created:				Sun 02 Jul 2000
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	viewcvs
PORTVERSION=	0.9.2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

USE_PYTHON=	yes
NO_BUILD=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
INSTDIR?=	${PORTNAME}-${PORTVERSION}
PLIST_SUB=	INSTDIR=${INSTDIR}

do-install:
	@ cd ${WRKSRC} && INSTDIR=${PREFIX}/${INSTDIR} ${PYTHON_CMD} viewcvs-install

post-install:
	@ ${SED} -e "s:%%INSTDIR%%:${PREFIX}/${INSTDIR}:g" pkg-message >${PKGMESSAGE}
.if !defined(BATCH)
	@ ${ECHO}
	@ ${CAT} ${PKGMESSAGE}
	@ ${ECHO}
.endif

.include <bsd.port.mk>
