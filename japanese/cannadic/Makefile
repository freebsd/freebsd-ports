# New ports collection makefile for:	cannadic
# Date created:		26 Oct 2000
# Whom:			TOGAWA Satoshi <toga@puyo.org>
#
# $FreeBSD$
#

PORTNAME=	cannadic
PORTVERSION=	0.94f
CATEGORIES=	japanese
MASTER_SITES=	http://cannadic.oucrc.org/

MAINTAINER=	toga@puyo.org

RUN_DEPENDS=	${LOCALBASE}/sbin/cannaserver:${PORTSDIR}/japanese/Canna
BUILD_DEPENDS=	crxdic:${PORTSDIR}/japanese/Canna

ALL_TARGET=	maindic

DICS=		gcanna.cbd gcanna.cld gcannaf.t
DICSFILE=	dics.dir.gpl_canna
DICDIR=		${PREFIX}/lib/canna/dic/canna

do-install:
	cd ${WRKSRC};\
	${INSTALL} -c -g bin -m 664 -o bin ${DICS} ${DICSFILE} ${DICDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${FILESDIR}/README.FreeBSD ${DOCSDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
