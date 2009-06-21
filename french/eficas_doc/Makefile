# New ports collection makefile for:	eficas-doc
# Date created:		15 June 2009
# Whom:			Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=	eficas_doc
DISTVERSIONPREFIX=	full-src-
DISTVERSION=	1.16.0-1
DISTVERSIONSUFFIX=	.noarch
CATEGORIES=	french cad
MASTER_SITES=	http://www.code-aster.org/V2/UPLOAD/DOC/Telechargement/
DISTNAME=	aster-${DISTVERSIONPREFIX}${ASTER_DISTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	ASter Command FIle Editor - doc files

RUN_DEPENDS=	eficas:${PORTSDIR}/french/eficas

ASTER_VER=	10.0.3
ASTER_DISTVERSION=	${ASTER_VER}-2
EXTRACT_WRKSRC=	${WRKDIR}/aster-${DISTVERSIONPREFIX}${ASTER_VER}/SRC

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME:S/_doc//}-${PORTVERSION:R}/Aster
PKG_INSTALL=	pkg-install

DOCSDIR=	${PREFIX}/share/doc/eficas
LEFICASDIR?=	apps/${PORTNAME:S/_doc//}
EFICASDIR=	${PREFIX}/${LEFICASDIR}
PLIST_SUB=	EFICASDIR=${LEFICASDIR}

post-extract:
	(cd ${WRKDIR} &&	\
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${EXTRACT_WRKSRC}/${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} ${EXTRACT_AFTER_ARGS})

pre-install:
	PKG_PREFIX=${PREFIX} ${SH} ${PKG_INSTALL} ${PKGNAME} PRE-INSTALL

do-install:
	${MKDIR} ${DOCSDIR} ${EFICASDIR}/Aster/Cata
	(cd ${WRKSRC}/Doc && ${COPYTREE_SHARE} \* ${DOCSDIR})
	(cd ${WRKSRC}/Cata &&	\
		${COPYTREE_SHARE} \* ${EFICASDIR}/Aster/Cata)

.include <bsd.port.mk>
