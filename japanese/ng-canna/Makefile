# New ports collection Makefile for: ja-ng-canna
# Date created:		11 January 1999
# Whom:				HONDA Yasuhiro <honda@kashio.info.mie-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	ng
PORTVERSION=	1.3L
PKGNAMESUFFIX=	-canna
CATEGORIES=	japanese editors
MASTER_SITES=	http://www3.tky.3web.ne.jp/~quiver/ng/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//}canna1.0.2

MAINTAINER=	honda@kashio.info.mie-u.ac.jp

LIB_DEPENDS=    canna:${PORTSDIR}/japanese/Canna

WRKSRC=		${WRKDIR}/${PORTNAME}
ALL_TARGET=	ng

post-patch:
	@(cd ${WRKSRC} ;  $(LN) -s sys/bsd/Makefile.canna ./Makefile )

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ng ${PREFIX}/bin/

post-install:
	${MKDIR} ${PREFIX}/share/doc/ja/ng
	${INSTALL_DATA} ${WRKSRC}/doc/Ng.doc ${PREFIX}/share/doc/ja/ng/Ng.doc.euc-jp
	${INSTALL_DATA} ${WRKSRC}/doc/Ng.ref ${PREFIX}/share/doc/ja/ng/Ng.ref.euc-jp
	${INSTALL_DATA} ${WRKSRC}/doc/Ng.tut ${PREFIX}/share/doc/ja/ng/Ng.tut.euc-jp

.include <bsd.port.mk>
