# New ports collection makefile for:	BladeEnc
# Version required:	0.76
# Date created:		Thu Jan 14 23:28:40 CET 1999
# Whom:			Dirk Froemberg <dirk@FreeBSD.ORG>
#
# $Id: Makefile,v 1.1.1.1 1999/01/14 23:42:52 dirk Exp $
#

DISTNAME=	BladeEnc-076-bsd-i386
PKGNAME=	bladeenc-0.76
CATEGORIES=	audio
MASTER_SITES=	http://home8.swipnet.se/~w-82625/encoder/binaries/ \
		http://www.physik.TU-Berlin.DE/~ibex/ports/distfiles/

MAINTAINER=	dirk@FreeBSD.ORG

ONLY_FOR_ARCHS=	i386
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bladeenc ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/BladeEnc
	${INSTALL_DATA} ${WRKSRC}/BladeEnc.html ${PREFIX}/share/doc/BladeEnc
.endif

.include <bsd.port.mk>
