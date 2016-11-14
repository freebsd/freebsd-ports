# Created by: Jonathan Shoemaker <shoemaker@bluebottle.com>
# $FreeBSD$

PORTNAME=	crafty-tablebase-pawn
PORTVERSION=	20070910
CATEGORIES=	games
MASTER_SITES=	http://www.cis.uab.edu/hyatt/crafty/TB/3-4-5/
DISTFILES=	kbbkp.nbb.emd kbbkp.nbw.emd kbbpk.nbb.emd kbbpk.nbw.emd	\
kbkp.nbb.emd kbkp.nbw.emd kbnkp.nbb.emd kbnkp.nbw.emd kbnpk.nbb.emd	\
kbnpk.nbw.emd kbpk.nbb.emd kbpk.nbw.emd kbpkb.nbb.emd kbpkb.nbw.emd	\
kbpkn.nbb.emd kbpkn.nbw.emd kbpkp.nbb.emd kbpkp.nbw.emd kbpkq.nbb.emd	\
kbpkq.nbw.emd kbpkr.nbb.emd kbpkr.nbw.emd kbppk.nbb.emd kbppk.nbw.emd	\
knkp.nbb.emd knkp.nbw.emd knnkp.nbb.emd knnkp.nbw.emd knnpk.nbb.emd	\
knnpk.nbw.emd knpk.nbb.emd knpk.nbw.emd knpkb.nbb.emd knpkb.nbw.emd	\
knpkn.nbb.emd knpkn.nbw.emd knpkp.nbb.emd knpkp.nbw.emd knpkq.nbb.emd	\
knpkq.nbw.emd knpkr.nbb.emd knpkr.nbw.emd knppk.nbb.emd knppk.nbw.emd	\
kpk.nbb.emd kpk.nbw.emd kpkp.nbb.emd kpkp.nbw.emd kppk.nbb.emd		\
kppk.nbw.emd kppkb.nbb.emd kppkb.nbw.emd kppkn.nbb.emd kppkn.nbw.emd	\
kppkp.nbb.emd kppkp.nbw.emd kppkq.nbb.emd kppkq.nbw.emd kppkr.nbb.emd	\
kppkr.nbw.emd kpppk.nbb.emd kpppk.nbw.emd kqbkp.nbb.emd kqbkp.nbw.emd	\
kqbpk.nbb.emd kqbpk.nbw.emd kqkp.nbb.emd kqkp.nbw.emd kqnkp.nbb.emd	\
kqnkp.nbw.emd kqnpk.nbb.emd kqnpk.nbw.emd kqpk.nbb.emd kqpk.nbw.emd	\
kqpkb.nbb.emd kqpkb.nbw.emd kqpkn.nbb.emd kqpkn.nbw.emd kqpkp.nbb.emd	\
kqpkp.nbw.emd kqpkq.nbb.emd kqpkq.nbw.emd kqpkr.nbb.emd kqpkr.nbw.emd	\
kqppk.nbb.emd kqppk.nbw.emd kqqkp.nbb.emd kqqkp.nbw.emd kqqpk.nbb.emd	\
kqqpk.nbw.emd kqrkp.nbb.emd kqrkp.nbw.emd kqrpk.nbb.emd kqrpk.nbw.emd	\
krbkp.nbb.emd krbkp.nbw.emd krbpk.nbb.emd krbpk.nbw.emd krkp.nbb.emd	\
krkp.nbw.emd krnkp.nbb.emd krnkp.nbw.emd krnpk.nbb.emd krnpk.nbw.emd	\
krpk.nbb.emd krpk.nbw.emd krpkb.nbb.emd krpkb.nbw.emd krpkn.nbb.emd	\
krpkn.nbw.emd krpkp.nbb.emd krpkp.nbw.emd krpkq.nbb.emd krpkq.nbw.emd	\
krpkr.nbb.emd krpkr.nbw.emd krppk.nbb.emd krppk.nbw.emd krrkp.nbb.emd	\
krrkp.nbw.emd krrpk.nbb.emd krrpk.nbw.emd
DIST_SUBDIR=	crafty
EXTRACT_ONLY=	# empty

MAINTAINER=	ports@FreeBSD.org
COMMENT=	These are the pawn tablebases (3,4,5 man) for crafty

RUN_DEPENDS=	crafty:games/crafty

NO_BUILD=	yes
NO_ARCH=	yes

BROKEN_aarch64=		Fails to install: runaway process
BROKEN_mips64=		Fails to install: runaway process

.if !defined(WITH_TBDIR)
WITH_TBDIR=	${PREFIX}/lib/crafty/TB
.endif

do-install:
	${MKDIR} ${STAGEDIR}${WITH_TBDIR}
	@list='${DISTFILES}'; for i in $$list; do \
		${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/$$i ${STAGEDIR}${WITH_TBDIR}/$$i; \
	done

.include <bsd.port.mk>
