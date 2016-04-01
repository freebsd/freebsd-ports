# Created by: TOGAWA Satoshi <toga@puyo.org>
# $FreeBSD$

PORTNAME=	cannadic
PORTVERSION=	0.95c
PORTREVISION=	3
CATEGORIES=	japanese
MASTER_SITES=	http://cannadic.oucrc.org/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Canna dictionary containing a lot of words

RUN_DEPENDS=	${LOCALBASE}/sbin/cannaserver:japanese/canna-server
BUILD_DEPENDS=	crxdic:japanese/canna-server

ALL_TARGET=	maindic
SUB_FILES=	README.FreeBSD pkg-message
PORTDOCS=	README.ja README.FreeBSD
PKGMESSAGE=	${WRKDIR}/pkg-message

DICS=		gcanna.cbd gcanna.cld gcannaf.ctd
DICSFILE=	dics.dir.gpl_canna
DICDIR=		share/canna/dic/canna
OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${DICDIR}
	cd ${WRKSRC} && \
		${INSTALL_DATA} ${DICS} ${DICSFILE} ${STAGEDIR}${PREFIX}/${DICDIR}
	${INSTALL_DATA} ${WRKDIR}/README.FreeBSD ${WRKSRC}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
