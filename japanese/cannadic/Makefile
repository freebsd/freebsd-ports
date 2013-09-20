# Created by: TOGAWA Satoshi <toga@puyo.org>
# $FreeBSD$

PORTNAME=	cannadic
PORTVERSION=	0.95c
PORTREVISION=	2
CATEGORIES=	japanese
MASTER_SITES=	http://cannadic.oucrc.org/

MAINTAINER=	toga@puyo.org
COMMENT=	A canna dictionary containing a lot of words

RUN_DEPENDS=	${LOCALBASE}/sbin/cannaserver:${PORTSDIR}/japanese/canna-server
BUILD_DEPENDS=	crxdic:${PORTSDIR}/japanese/canna-server

ALL_TARGET=	maindic
SUB_FILES=	README.FreeBSD pkg-message
PORTDOCS=	README.ja README.FreeBSD
PKGMESSAGE=	${WRKDIR}/pkg-message

DICS=		gcanna.cbd gcanna.cld gcannaf.ctd
DICSFILE=	dics.dir.gpl_canna
DICDIR=		${LOCALBASE}/share/canna/dic/canna

NO_STAGE=	yes
do-install:
	cd ${WRKSRC} && \
	${INSTALL} -c -g bin -m 664 -o bin ${DICS} ${DICSFILE} ${DICDIR}
	${INSTALL_DATA} ${WRKDIR}/README.FreeBSD ${WRKSRC}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
