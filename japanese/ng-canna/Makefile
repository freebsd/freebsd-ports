# New ports collection Makefile for: ja-ng-canna
# Version required:	ng1.3Lcanna1.0.2
# Date created:		11 January 1999
# Whom:				HONDA Yasuhiro <honda@kashio.info.mie-u.ac.jp>
#
# $Id$
#

DISTNAME=	ng13Lcanna1.0.2
PKGNAME=	ja-ng-canna-1.3l
CATEGORIES=	japanese editors
MASTER_SITES=	http://www3.tky.3web.ne.jp/~quiver/ng/

MAINTAINER=	honda@kashio.info.mie-u.ac.jp

LIB_DEPENDS=    canna:${PORTSDIR}/japanese/Canna

WRKSRC=		${WRKDIR}/ng
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
