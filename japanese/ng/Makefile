# New ports collection makefile for:    Ng
# Date created:         18 November 1998
# Whom:                 Kawaguti Ginga <ginga@athena.club.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	ng
PORTVERSION=	1.3L
CATEGORIES=     japanese editors
MASTER_SITES=   ftp://ftp.iis.u-tokyo.ac.jp/unix/Editor/

MAINTAINER=     ginga@athena.club.ne.jp

WRKSRC=         ${WRKDIR}/Ng-${PORTVERSION}
ALL_TARGET=	ng

post-patch:
	@(cd ${WRKSRC}; ${LN} -s sys/bsd/Makefile . )

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ng ${PREFIX}/bin/

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ja/ng
	${INSTALL_DATA} ${WRKSRC}/Ng.doc ${PREFIX}/share/doc/ja/ng/Ng.doc.euc-jp
	${INSTALL_DATA} ${WRKSRC}/Ng.ref ${PREFIX}/share/doc/ja/ng/Ng.ref.euc-jp
	${INSTALL_DATA} ${WRKSRC}/Ng.tut ${PREFIX}/share/doc/ja/ng/Ng.tut.euc-jp
.endif

.include <bsd.port.mk>
