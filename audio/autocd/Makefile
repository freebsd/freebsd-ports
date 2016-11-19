# Created by: Dmitry Afanasiev <KOT@MATPOCKuH.Ru>
# $FreeBSD$

PORTNAME=	autocd
PORTVERSION=	3.02.12b
PORTREVISION=	3
CATEGORIES=	audio sysutils
MASTER_SITES=	ftp://kot.spb.ru/pub/src/projects/autocd/

MAINTAINER=	KOT@MATPOCKuH.Ru
COMMENT=	Compact disc control utility

USES=		libedit ncurses
GNU_CONFIGURE=	yes

PORTDOCS=	README.rus.html

USE_RC_SUBR=	autocd

OPTIONS_DEFINE=	DOCS

do-install:
	@(cd ${WRKSRC} && ${INSTALL_PROGRAM} acdplay cdctl \
		${STAGEDIR}${PREFIX}/bin/)
	${INSTALL_PROGRAM} ${WRKSRC}/autocd ${STAGEDIR}${PREFIX}/sbin
	@(cd ${STAGEDIR}${PREFIX}/bin && \
		ln -s cdctl pause && \
		ln -s cdctl eject)
	@(cd ${WRKSRC} && ${INSTALL_MAN} acdplay.1 cdctl.1 \
		${STAGEDIR}${PREFIX}/man/man1/)
	${INSTALL_MAN} ${WRKSRC}/autocd.8 ${STAGEDIR}${PREFIX}/man/man8/

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
