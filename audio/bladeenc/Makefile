# New ports collection makefile for:	BladeEnc
# Version required:	0.82
# Date created:		Thu Jan 14 23:28:40 CET 1999
# Whom:			Dirk Froemberg <dirk@FreeBSD.org>
#
# $Id: Makefile,v 1.4 1999/04/24 17:25:49 kris Exp $
#

DISTNAME=	bladeenc-082-src-stable
PKGNAME=	bladeenc-082
CATEGORIES=	audio
MASTER_SITES=	http://home8.swipnet.se/~w-82625/encoder/binaries/ \
		http://www.physik.TU-Berlin.DE/~ibex/ports/distfiles/

MAINTAINER=	dirk@FreeBSD.org

pre-build:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bladeenc ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/bladeenc
	${INSTALL_DATA} ${WRKSRC}/bladeenc.html ${PREFIX}/share/doc/bladeenc
.endif

.include <bsd.port.mk>
