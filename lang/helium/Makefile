# New ports collection makefile for:	helium
# Date created:				28 January 2003
# Whom:					Oliver Braun <obraun@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	helium
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	lang haskell
MASTER_SITES=	http://www.cs.uu.nl/helium/distr/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	obraun@FreeBSD.org
COMMENT=	Functional programming compiler for a subset of Haskell

.include <bsd.port.pre.mk>
.if ${OSVERSION} >= 500035
BROKEN=	does not compile
.endif

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_REINPLACE=	yes
USE_GMAKE=	yes

do-configure:
	@(cd ${WRKSRC}/lvm/src/  && ./configure)
	@(cd ${WRKSRC}/heliumNT/ && ./configure)

do-build:
	@(cd ${WRKSRC}/heliumNT/src && ${GMAKE} depend)
	@(cd ${WRKSRC}/heliumNT/src && ${GMAKE})

do-install:
	@(cd ${WRKSRC}/heliumNT/src && ${GMAKE} install)
	@${CAT} ${PKGMESSAGE} | ${SED} -e 's,%%PREFIX%%,${PREFIX},g'

.include <bsd.port.post.mk>
