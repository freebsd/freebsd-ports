# New ports collection makefile for:	cannadic
# Date created:		26 Oct 2000
# Whom:			TOGAWA Satoshi <toga@puyo.org>
#
# $FreeBSD$
#

PORTNAME=	cannadic
PORTVERSION=	0.93a
CATEGORIES=	japanese
MASTER_SITES=	http://cannadic.oucrc.org/

MAINTAINER=	toga@puyo.org

RUN_DEPENDS=	${LOCALBASE}/lib/canna/dic/canna/dics.dir:${PORTSDIR}/japanese/Canna
BUILD_DEPENDS=	crxdic:${PORTSDIR}/japanese/Canna

ALL_TARGET=	maindic subdic

DICS=		gcanna.cbd gcanna.cld gcannaf.cbd gcannaf.cld
DICSFILE=	dics.dir
ORIGDICSFILE=	dics.dir.orig
CANNADICSFILE=	dics.dir.gpl_canna
CANNASH=	${PREFIX}/etc/rc.d/canna.sh
DICDIR=		${PREFIX}/lib/canna/dic/canna

do-install:
	cd ${WRKSRC};\
	${CP} ${DICDIR}/${DICSFILE} ./${ORIGDICSFILE}; \
	${CAT} ./${ORIGDICSFILE} ./${CANNADICSFILE} > ./${DICSFILE}; \
	${INSTALL} -c -g bin -m 664 -o bin ${DICS} ${DICDIR} ; \
	${INSTALL} -c -g bin -m 664 -o bin ${DICSFILE} ${CANNADICSFILE} ${ORIGDICSFILE} ${DICDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

post-install:
	@if [ -e /tmp/.iroha_unix/IROHA ]; then \
	   ${ECHO} "Restarting Canna server..."; \
	   ${CANNASH} stop > /dev/null 2>&1 ; \
	   ${CANNASH} start > /dev/null 2>&1 ; \
	 fi
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
