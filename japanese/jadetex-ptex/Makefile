# New ports collection makefile for:    jadetex-ptex
# Date created:         11 June 2003
# Whom:                 Hiroki Sato <hrs@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=		jadetex
PORTVERSION=		3.13
CATEGORIES=		japanese print
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	jadetex
PKGNAMESUFFIX=		-ptex
DISTNAME=		jadetex-${PORTVERSION}

MAINTAINER=		hrs@FreeBSD.org
COMMENT=		A pTeX backend for Jade, for typesetting SGML documents

BUILD_DEPENDS=		ptex:${PORTSDIR}/japanese/ptex
LIB_DEPENDS=		png.5:${PORTSDIR}/graphics/png
RUN_DEPENDS=		ptex:${PORTSDIR}/japanese/ptex

MESSAGE=		${PKGDIR}/pkg-message
PKGMESSAGE=		${WRKDIR}/pkg-message

pre-patch:
	@${SED} -e 's,%%LOCALBASE%%,${LOCALBASE},' ${MESSAGE} > ${PKGMESSAGE}

post-install: rebuild-tex-database display-message
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}${PKGNAMESUFFIX}
	${INSTALL_MAN} ${WRKSRC}/README.jadetex-ptex ${DOCSDIR}${PKGNAMESUFFIX}
.endif

rebuild-tex-database:
	${LOCALBASE}/bin/mktexlsr

display-message:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
