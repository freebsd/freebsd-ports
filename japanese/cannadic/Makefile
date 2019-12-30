# Created by: TOGAWA Satoshi <toga@puyo.org>
# $FreeBSD$

PORTNAME=	cannadic
PORTVERSION=	0.95c
PORTREVISION=	4
CATEGORIES=	japanese
MASTER_SITES=	LOCAL/hrs

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Canna dictionary containing a lot of words

LICENSE=	GPLv2

RUN_DEPENDS=	${LOCALBASE}/sbin/cannaserver:japanese/canna-server
BUILD_DEPENDS=	crxdic:japanese/canna-server

ALL_TARGET=	maindic
SUB_FILES=	README.FreeBSD pkg-message
PORTDOCS=	README.ja README.FreeBSD

DICS=		gcanna.cbd gcanna.cld gcannaf.ctd
DICSFILE=	dics.dir.gpl_canna
DICDIR=		share/canna/dic/canna
OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${DICDIR}
	cd ${WRKSRC} && \
	    ${INSTALL_DATA} ${DICS} ${DICSFILE} ${STAGEDIR}${PREFIX}/${DICDIR}
	${INSTALL_DATA} ${WRKDIR}/README.FreeBSD ${WRKSRC}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
