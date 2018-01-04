# $FreeBSD$

PORTNAME=	ebook2cwgui
PORTVERSION=	0.1.2
PORTREVISION=	2
CATEGORIES=	comms hamradio
MASTER_SITES=	http://fkurz.net/ham/ebook4cw/

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Gui front end for ebooks2cw

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	ebook2cw:comms/ebook2cw

USE_WX=		2.8

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|wx-config|${WX_CONFIG:S,${PREFIX}/bin/,,}|g' \
	     ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|/usr|${PREFIX}|g' \
		-e 's|g++|${CXX}|g' \
	     ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ebook2cwgui ${STAGEDIR}${PREFIX}/bin/ebook2cwgui
	${INSTALL_DATA} ${WRKSRC}/ebook2cwgui.1 ${STAGEDIR}${MANPREFIX}/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in README ChangeLog
	${INSTALL_DATA} ${WRKSRC}/$f ${STAGEDIR}${DOCSDIR}/$f
.endfor

.include <bsd.port.mk>
