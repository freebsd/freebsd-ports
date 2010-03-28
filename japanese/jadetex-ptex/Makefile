# New ports collection makefile for:    jadetex-ptex
# Date created:         11 June 2003
# Whom:                 Hiroki Sato <hrs@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jadetex
PORTVERSION=	3.13
PORTREVISION=	9
CATEGORIES=	japanese print
MASTER_SITES=	SF
PKGNAMESUFFIX=	-ptex
DISTNAME=	jadetex-${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	A pTeX backend for Jade, for typesetting SGML documents

BUILD_DEPENDS=	ptex:${PORTSDIR}/japanese/ptex
LIB_DEPENDS=	png.6:${PORTSDIR}/graphics/png
RUN_DEPENDS=	ptex:${PORTSDIR}/japanese/ptex

PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message

PLIST_SUB=	PKGNAMESUFFIX=${PKGNAMESUFFIX} \
		MKTEXLSR=${MKTEXLSR} \
		TEXMFDIR=${TEXMFDIR} \
		TEXMFLOCALDIR=${TEXMFLOCALDIR}

MKTEXLSR=	${LOCALBASE}/bin/mktexlsr
TEXMFDIR=	share/texmf
TEXMFLOCALDIR=	share/texmf-local

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}${PKGNAMESUFFIX}
	${INSTALL_MAN} ${WRKSRC}/README.jadetex-ptex ${DOCSDIR}${PKGNAMESUFFIX}/
.endif
	${LOCALBASE}/bin/mktexlsr ${LOCALBASE}/${TEXMFDIR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
