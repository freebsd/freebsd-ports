# New ports collection makefile for:    Ng
# Date created:         18 November 1998
# Whom:                 Kawaguti Ginga <ginga@athena.club.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	ng
PORTVERSION=	1.4.b5
CATEGORIES=     japanese editors
MASTER_SITES=   http://ha3.seikyou.ne.jp/home/amura/archives/ng/
DISTNAME=	${PORTNAME}-1.4beta5

MAINTAINER=     ginga@athena.club.ne.jp

WRKSRC=         ${WRKDIR}/ng
ALL_TARGET=	ng

post-patch:
	@(cd ${WRKSRC}; ${LN} -s sys/bsd/Makefile . )

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ng ${PREFIX}/bin/

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ja/ng
	${INSTALL_DATA} ${WRKSRC}/docs/Ng.FAQ ${PREFIX}/share/doc/ja/ng/Ng.FAQ.euc-jp
	${INSTALL_DATA} ${WRKSRC}/docs/Ng.doc ${PREFIX}/share/doc/ja/ng/Ng.doc.euc-jp
	${INSTALL_DATA} ${WRKSRC}/docs/Ng.ref ${PREFIX}/share/doc/ja/ng/Ng.ref.euc-jp
	${INSTALL_DATA} ${WRKSRC}/docs/Ng.tut ${PREFIX}/share/doc/ja/ng/Ng.tut.euc-jp
	${INSTALL_DATA} ${WRKSRC}/docs/README.Ng ${PREFIX}/share/doc/ja/ng/README.Ng.euc-jp
	${INSTALL_DATA} ${WRKSRC}/docs/README.SKG ${PREFIX}/share/doc/ja/ng/README.SKG.euc-jp
	${INSTALL_DATA} ${WRKSRC}/docs/CHANGES.new ${PREFIX}/share/doc/ja/ng/CHANGES.new.euc-jp
	${INSTALL_DATA} ${WRKSRC}/docs/CHANGES.doc ${PREFIX}/share/doc/ja/ng/CHANGES.doc.euc-jp
.endif

.include <bsd.port.mk>
