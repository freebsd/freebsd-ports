PORTNAME=	hexcompare
PORTVERSION=	1.0.4
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20v${PORTVERSION}

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Compare and identify differences between two binary files

LICENSE=	GPLv3

USES=		ncurses
PLIST_FILES=	bin/hexcompare

post-patch:
	@${REINPLACE_CMD} -e 's|gcc|${CC}|g' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|-lncurses|$$(CFLAGS) $$(LDFLAGS) -lncurses|' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
