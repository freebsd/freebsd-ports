# New ports collection makefile for:	helium
# Date created:				28 January 2003
# Whom:					Oliver Braun <obraun@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	helium
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	lang haskell
MASTER_SITES=	http://www.cs.uu.nl/~afie/helium/
DISTNAME=	${PORTNAME}
#DISTFILES=	${PORTNAME}${EXTRACT_SUFX}

MAINTAINER=	obraun@FreeBSD.org

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc
RUN_DEPENDS=	ghc:${PORTSDIR}/lang/ghc

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_REINPLACE=	yes
USE_GMAKE=	yes

post-patch:
	${REINPLACE_CMD} -e 's/hi$$(EXE)/helium-i/g' \
		${WRKSRC}/heliumNT/src/Makefile.in

do-configure:
	@(cd ${WRKSRC}/lvm/src/  && ./configure)
	@(cd ${WRKSRC}/heliumNT/ && ./configure)

do-build:
	@(cd ${WRKSRC}/heliumNT/src && ${GMAKE} depend)
	@(cd ${WRKSRC}/heliumNT/src && ${GMAKE})

do-install:
	@(cd ${WRKSRC}/heliumNT/src && ${GMAKE} install)
	@${CAT} ${PKGMESSAGE} | ${SED} -e 's,%%PREFIX%%,${PREFIX},g'

.include <bsd.port.mk>
