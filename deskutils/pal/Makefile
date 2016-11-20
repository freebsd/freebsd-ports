# Created by: Herbert J. Skuhra <h.skuhra@gmail.com>
# $FreeBSD$

PORTNAME=	pal
PORTVERSION=	0.4.3
CATEGORIES=	deskutils
MASTER_SITES=	SF/${PORTNAME}cal/${PORTNAME}/${PORTVERSION}

MAINTAINER=	h.skuhra@gmail.com
COMMENT=	Calendar application

USES=		gettext gmake ncurses pkgconfig readline tar:tgz
USE_GNOME=	glib20
ALL_TARGET=
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

post-patch:
	@${REINPLACE_CMD} -e "s,prefix = /usr,prefix = ${PREFIX},g;s,^CC,#CC,g" \
		${WRKSRC}/Makefile.defs

post-build:
	${REINPLACE_CMD} -e "s,VERSION,${PORTVERSION},g" \
		${WRKDIR}/${PORTNAME}-${PORTVERSION}/pal.1.template

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pal ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}-${PORTVERSION}/share/*.pal \
		${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}-${PORTVERSION}/pal.conf \
		${STAGEDIR}${DATADIR}
	${INSTALL_MAN} ${WRKDIR}/${PORTNAME}-${PORTVERSION}/pal.1.template \
		${STAGEDIR}${MANPREFIX}/man/man1/pal.1

.include <bsd.port.mk>
