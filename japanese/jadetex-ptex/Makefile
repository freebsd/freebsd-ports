# New ports collection makefile for:    jadetex-ptex
# Date created:         11 June 2003
# Whom:                 Hiroki Sato <hrs@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=		jadetex
PORTVERSION=		3.13
PORTREVISION=		3
CATEGORIES=		japanese print
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMESUFFIX=		-ptex
DISTNAME=		jadetex-${PORTVERSION}

MAINTAINER=		hrs@FreeBSD.org
COMMENT=		A pTeX backend for Jade, for typesetting SGML documents

BUILD_DEPENDS=		ptex:${PORTSDIR}/japanese/ptex-tetex
LIB_DEPENDS=		png.5:${PORTSDIR}/graphics/png
RUN_DEPENDS=		ptex:${PORTSDIR}/japanese/ptex-tetex

PKGMESSAGE=		${WRKDIR}/pkg-message
PKGMESSAGE_SUB=		LOCALBASE=${LOCALBASE}

PLIST_SUB=		PKGNAMESUFFIX=${PKGNAMESUFFIX} \
			MKTEXLSR=${MKTEXLSR} \
			TEXMFDIR=${TEXMFDIR} \
			TEXMFLOCALDIR=${TEXMFLOCALDIR}

MKTEXLSR=	${LOCALBASE}/bin/mktexlsr
TEXMFDIR=	share/texmf
TEXMFLOCALDIR=	share/texmf-local

pre-patch:
	${SED} ${PKGMESSAGE_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		< ${PKGDIR}/pkg-message > ${PKGMESSAGE}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}${PKGNAMESUFFIX}
	${INSTALL_MAN} ${WRKSRC}/README.jadetex-ptex ${DOCSDIR}${PKGNAMESUFFIX}/
.endif
	${LOCALBASE}/bin/mktexlsr
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
