# Created by: Herbert J. Skuhra <h.skuhra@gmail.com>
# $FreeBSD$

PORTNAME=	pal
PORTVERSION=	0.4.3
CATEGORIES=	deskutils
MASTER_SITES=	SF/${PORTNAME}cal/${PORTNAME}/${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	h.skuhra@gmail.com
COMMENT=	Calendar application

USES=		pkgconfig gettext gmake
USE_GNOME=	glib20
USE_GMAKE=	yes
ALL_TARGET=
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

MAN1=		pal.1

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e "s,prefix = /usr,prefix = ${PREFIX},g;s,^CC,#CC,g" ${WRKSRC}/Makefile.defs

post-build:
	${REINPLACE_CMD} -e "s,VERSION,${PORTVERSION},g" ${WRKDIR}/${PORTNAME}-${PORTVERSION}/pal.1.template

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pal ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}-${PORTVERSION}/share/*.pal ${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}-${PORTVERSION}/pal.conf ${DATADIR}
	${INSTALL_MAN} ${WRKDIR}/${PORTNAME}-${PORTVERSION}/pal.1.template ${PREFIX}/man/man1/pal.1

.include <bsd.port.post.mk>
