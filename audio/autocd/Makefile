# Created by: Dmitry Afanasiev <KOT@MATPOCKuH.Ru>
# $FreeBSD$

PORTNAME=	autocd
PORTVERSION=	3.02.12b
PORTREVISION=	1
CATEGORIES=	audio sysutils
MASTER_SITES=	ftp://kot.spb.ru/pub/src/projects/autocd/

MAINTAINER=	KOT@MATPOCKuH.Ru
COMMENT=	Compact disc control utility

GNU_CONFIGURE=	yes

PORTDOCS=	README.rus.html

USE_RC_SUBR=	autocd

OPTIONS_DEFINE=	DOCS

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
