# New ports collection makefile for:	cannadic
# Date created:		26 Oct 2000
# Whom:			TOGAWA Satoshi <toga@puyo.org>
#
# $FreeBSD$
#

PORTNAME=	cannadic
PORTVERSION=	0.92
CATEGORIES=	japanese
MASTER_SITES=	http://cgi3.osk.3web.ne.jp/~nowaki/computer/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	toga@puyo.org

RUN_DEPENDS=	${LOCALBASE}/lib/canna/dic/canna/dics.dir:${PORTSDIR}/japanese/Canna
BUILD_DEPENDS=	mkbindic:${PORTSDIR}/japanese/Canna

DICS=		gcanna.d gcannaf.d
FQS=		gcanna.fq gcannaf.fq
DICSFILE=	dics.dir
ORIGDICSFILE=	dics.dir.orig
CANNADICSFILE=	dics.dir.gpl_canna
CANNASH=	${PREFIX}/etc/rc.d/canna.sh
DICDIR=		${PREFIX}/lib/canna/dic/canna

do-install:
	cd ${WRKSRC};\
	${CP} ${DICDIR}/${DICSFILE} ./${ORIGDICSFILE}; \
	${CAT} ./${ORIGDICSFILE} ./${CANNADICSFILE} > ./${DICSFILE}; \
	${INSTALL_DATA} -g bin -m 664 -o bin ${DICS} ${FQS} ${DICDIR};\
	${INSTALL_DATA} -g bin -m 664 -o bin ${DICSFILE} ${CANNADICSFILE} ${ORIGDICSFILE} ${DICDIR}

post-install:
	@( \
	${ECHO} ; \
	${ECHO} ; \
	${ECHO} "After installing, you have to restart cannaserver" ; \
	${ECHO} "and add lines to your .canna."; \
	${ECHO} "(use-dictionary" ; \
	${ECHO} "\"iroha\" ; and more...." ; \
	${ECHO} ; \
	${ECHO} "\"gcanna\"  ; add this!" ;\
	${ECHO} "\"gcannaf\" ; add this!" ;\
	${ECHO} ")";\
	${ECHO} ; \
	${ECHO} ; \
	)

.include <bsd.port.mk>
