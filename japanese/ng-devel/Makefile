# New ports collection makefile for:    Ng
# Version required:     1.3L
# Date created:         18 November 1998
# Whom:                 Kawaguti Ginga <ginga@athena.club.ne.jp>
#
# $FreeBSD$
#

DISTNAME=       ng-1.3L
PKGNAME=        ja-ng-1.3l
CATEGORIES=     japanese editors
MASTER_SITES=   ftp://ftp.iis.u-tokyo.ac.jp/unix/Editor/

MAINTAINER=     ginga@athena.club.ne.jp

WRKSRC=         ${WRKDIR}/Ng-1.3L
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
