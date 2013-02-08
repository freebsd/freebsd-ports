# New ports collection makefile for:	eficas-doc
# Date created:		15 June 2009
# Whom:			Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=	eficas-doc
DISTVERSION=	6.4.0-1
PORTREVISION=	1
CATEGORIES=	french cad

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	ASter Command FIle Editor - doc files

RUN_DEPENDS=	eficas:${PORTSDIR}/french/eficas

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME:S/-doc//}-${PORTVERSION:R}/Aster
PKG_INSTALL=	pkg-install

DOCSDIR=	${PREFIX}/share/doc/eficas
LEFICASDIR?=	apps/${PORTNAME:S/-doc//}
EFICASDIR=	${PREFIX}/${LEFICASDIR}
PLIST_SUB=	EFICASDIR=${LEFICASDIR} ASTER_VER=STA${ASTER_VER:R} ASTER_VER+1=STA11.1

pre-install:
	PKG_PREFIX=${PREFIX} ${SH} ${PKG_INSTALL} ${PKGNAME} PRE-INSTALL

do-install:
	${MKDIR} ${DOCSDIR} ${EFICASDIR}/Aster/Cata
	(cd ${WRKSRC}/Doc && ${COPYTREE_SHARE} \* ${DOCSDIR})
	(cd ${WRKSRC}/Cata &&	\
		${COPYTREE_SHARE} \* ${EFICASDIR}/Aster/Cata)

.include "${.CURDIR}/../../french/aster/bsd.aster.mk"
.include <bsd.port.mk>
