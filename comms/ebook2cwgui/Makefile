# $FreeBSD$

PORTNAME=	ebook2cwgui
PORTVERSION=	0.1.2
CATEGORIES=	comms hamradio
MASTER_SITES=	http://fkurz.net/ham/ebook2cw/ \
		http://distfiles.bsdjunk.com/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	db

MAINTAINER=	db@FreeBSD.org
COMMENT=	gui front end for ebooks2cw

RUN_DEPENDS=	ebook2cw:${PORTSDIR}/comms/ebook2cw

USE_WX=	2.8
WX_UNICODE=	yes

PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} -e 's|wx-config|${WX_CONFIG:S,${PREFIX}/bin/,,}|g' \
	     ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|/usr|${PREFIX}|g' \
		-e 's|g++|${CXX}|g' \
	     ${WRKSRC}/Makefile

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/ebook2cwgui ${STAGEDIR}${PREFIX}/bin/ebook2cwgui
	@${INSTALL_DATA} ${WRKSRC}/ebook2cwgui.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for 	f in README COPYING ChangeLog
	@${INSTALL_DATA} ${WRKSRC}/$f ${STAGEDIR}${DOCSDIR}/$f
.endfor

.include <bsd.port.mk>
