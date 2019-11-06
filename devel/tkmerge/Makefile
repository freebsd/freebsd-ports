# Created by: Bob Willcox <bob@immure.com>
# $FreeBSD$

PORTNAME=	tkmerge
PORTVERSION=	0.85
PORTREVISION=	1
CATEGORIES=	devel tk
MASTER_SITES=	http://immure.com/ports/tkmerge/

MAINTAINER=	bob@immure.com
COMMENT=	Tk script to aid in merging changes between two files

BROKEN=		unfetchable

RUN_DEPENDS+=	${LOCALBASE}/lib/bwidget/label.tcl:x11-toolkits/bwidget

USES=		tk:run

NO_BUILD=	yes
PLIST_FILES=	bin/tkmerge \
		man/man1/tkmerge.1.gz

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|wish8.4|${WISH}|g' ${WRKSRC}/tkmerge

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tkmerge ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/tkmerge.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.post.mk>
