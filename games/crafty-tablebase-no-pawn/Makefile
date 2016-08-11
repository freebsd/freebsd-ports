# Created by: Jonathan Shoemaker <shoemaker@bluebottle.com>
# $FreeBSD$

PORTNAME=	crafty-tablebases-no-pawn
PORTVERSION=	20070910
CATEGORIES=	games
MASTER_SITES=	http://www.cis.uab.edu/hyatt/crafty/TB/3-4-5/
DISTFILES=	kbbbk.nbb.emd kbbbk.nbw.emd kbbk.nbb.emd kbbk.nbw.emd	\
kbbkb.nbb.emd kbbkb.nbw.emd kbbkn.nbb.emd kbbkn.nbw.emd kbbkq.nbb.emd	\
kbbkq.nbw.emd kbbkr.nbb.emd kbbkr.nbw.emd kbbnk.nbb.emd kbbnk.nbw.emd	\
kbk.nbb.emd kbk.nbw.emd kbkb.nbb.emd kbkb.nbw.emd kbkn.nbb.emd		\
kbkn.nbw.emd kbnk.nbb.emd kbnk.nbw.emd kbnkb.nbb.emd kbnkb.nbw.emd	\
kbnkn.nbb.emd kbnkn.nbw.emd kbnkq.nbb.emd kbnkq.nbw.emd kbnkr.nbb.emd	\
kbnkr.nbw.emd kbnnk.nbb.emd kbnnk.nbw.emd knk.nbb.emd knk.nbw.emd	\
knkn.nbb.emd knkn.nbw.emd knnk.nbb.emd knnk.nbw.emd knnkb.nbb.emd	\
knnkb.nbw.emd knnkn.nbb.emd knnkn.nbw.emd knnkq.nbb.emd knnkq.nbw.emd	\
knnkr.nbb.emd knnkr.nbw.emd knnnk.nbb.emd knnnk.nbw.emd kqbbk.nbb.emd	\
kqbbk.nbw.emd kqbk.nbb.emd kqbk.nbw.emd kqbkb.nbb.emd kqbkb.nbw.emd	\
kqbkn.nbb.emd kqbkn.nbw.emd kqbkq.nbb.emd kqbkq.nbw.emd kqbkr.nbb.emd	\
kqbkr.nbw.emd kqbnk.nbb.emd kqbnk.nbw.emd kqk.nbb.emd kqk.nbw.emd	\
kqkb.nbb.emd kqkb.nbw.emd kqkn.nbb.emd kqkn.nbw.emd kqkq.nbb.emd	\
kqkq.nbw.emd kqkr.nbb.emd kqkr.nbw.emd kqnk.nbb.emd kqnk.nbw.emd	\
kqnkb.nbb.emd kqnkb.nbw.emd kqnkn.nbb.emd kqnkn.nbw.emd kqnkq.nbb.emd	\
kqnkq.nbw.emd kqnkr.nbb.emd kqnkr.nbw.emd kqnnk.nbb.emd kqnnk.nbw.emd	\
kqqbk.nbb.emd kqqbk.nbw.emd kqqk.nbb.emd kqqk.nbw.emd kqqkb.nbb.emd	\
kqqkb.nbw.emd kqqkn.nbb.emd kqqkn.nbw.emd kqqkq.nbb.emd kqqkq.nbw.emd	\
kqqkr.nbb.emd kqqkr.nbw.emd kqqnk.nbb.emd kqqnk.nbw.emd kqqqk.nbb.emd	\
kqqqk.nbw.emd kqqrk.nbb.emd kqqrk.nbw.emd kqrbk.nbb.emd kqrbk.nbw.emd	\
kqrk.nbb.emd kqrk.nbw.emd kqrkb.nbb.emd kqrkb.nbw.emd kqrkn.nbb.emd	\
kqrkn.nbw.emd kqrkq.nbb.emd kqrkq.nbw.emd kqrkr.nbb.emd kqrkr.nbw.emd	\
kqrnk.nbb.emd kqrnk.nbw.emd kqrrk.nbb.emd kqrrk.nbw.emd krbbk.nbb.emd	\
krbbk.nbw.emd krbk.nbb.emd krbk.nbw.emd krbkb.nbb.emd krbkb.nbw.emd	\
krbkn.nbb.emd krbkn.nbw.emd krbkq.nbb.emd krbkq.nbw.emd krbkr.nbb.emd	\
krbkr.nbw.emd krbnk.nbb.emd krbnk.nbw.emd krk.nbb.emd krk.nbw.emd	\
krkb.nbb.emd krkb.nbw.emd krkn.nbb.emd krkn.nbw.emd krkr.nbb.emd	\
krkr.nbw.emd krnk.nbb.emd krnk.nbw.emd krnkb.nbb.emd krnkb.nbw.emd	\
krnkn.nbb.emd krnkn.nbw.emd krnkq.nbb.emd krnkq.nbw.emd krnkr.nbb.emd	\
krnkr.nbw.emd krnnk.nbb.emd krnnk.nbw.emd krrbk.nbb.emd krrbk.nbw.emd	\
krrk.nbb.emd krrk.nbw.emd krrkb.nbb.emd krrkb.nbw.emd krrkn.nbb.emd	\
krrkn.nbw.emd krrkq.nbb.emd krrkq.nbw.emd krrkr.nbb.emd krrkr.nbw.emd	\
krrnk.nbb.emd krrnk.nbw.emd krrrk.nbb.emd krrrk.nbw.emd
DIST_SUBDIR=	crafty
EXTRACT_ONLY=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	These are the tablebases for crafty, minus the pawn tbs

BROKEN_powerpc64=	Does not build

RUN_DEPENDS=	crafty:games/crafty

NO_BUILD=	yes

.if !defined(WITH_TBDIR)
WITH_TBDIR=	${PREFIX}/lib/crafty/TB
.endif

do-install:
	${MKDIR} ${STAGEDIR}${WITH_TBDIR}
	@list='${DISTFILES}'; for i in $$list; do \
		${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/$$i ${STAGEDIR}${WITH_TBDIR}/$$i; \
		done

.include <bsd.port.mk>
