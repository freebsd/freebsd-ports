# New ports collection makefile for:    Ng
# Date created:         18 November 1998
# Whom:                 Kawaguti Ginga <ginga@athena.club.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	ng
PORTVERSION=	1.4.3
CATEGORIES=	japanese editors
MASTER_SITES=	http://ha3.seikyou.ne.jp/home/amura/archives/ng/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ginga@athena.club.ne.jp

WRKSRC=		${WRKDIR}/${PORTNAME}
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" LIBS="-ltermcap"
ALL_TARGET=	ng

PORTDOCS=	CHANGES.doc CHANGES.new Ng.FAQ Ng.doc Ng.ref Ng.tut \
		README.Ng README.SKG

post-patch:
	@(cd ${WRKSRC}; ${LN} -sf sys/bsd/Makefile . )

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ng ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ja/ng
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/docs/${file} ${PREFIX}/share/doc/ja/ng/${file}.euc-jp
.endfor
.endif

.include <bsd.port.mk>
