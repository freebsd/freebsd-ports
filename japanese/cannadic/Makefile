# New ports collection makefile for:	cannadic
# Date created:		26 Oct 2000
# Whom:			TOGAWA Satoshi <toga@puyo.org>
#
# $FreeBSD$
#

PORTNAME=	cannadic
PORTVERSION=	0.95c
CATEGORIES=	japanese
MASTER_SITES=	http://cannadic.oucrc.org/

MAINTAINER=	toga@puyo.org
COMMENT=	A canna dictionary containing a lot of words

RUN_DEPENDS=	${LOCALBASE}/sbin/cannaserver:${PORTSDIR}/japanese/Canna
BUILD_DEPENDS=	crxdic:${PORTSDIR}/japanese/Canna

ALL_TARGET=	maindic

DICS=		gcanna.cbd gcanna.cld gcannaf.ctd
DICSFILE=	dics.dir.gpl_canna
DICDIR=		${PREFIX}/share/canna/dic/canna

do-install:
	cd ${WRKSRC};\
	${INSTALL} -c -g bin -m 664 -o bin ${DICS} ${DICSFILE} ${DICDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.ja ${DOCSDIR}
	${INSTALL_DATA} ${FILESDIR}/README.FreeBSD ${DOCSDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
