# Created by: Bob Willcox <bob@immure.com>
# $FreeBSD$

PORTNAME=	tkmerge
PORTVERSION=	0.85
PORTREVISION=	1
CATEGORIES=	devel tk
MASTER_SITES=	http://immure.com/ports/tkmerge/

MAINTAINER=	bob@immure.com
COMMENT=	A tk script to aid in the merging changes between two files

USE_TK_RUN=	84+

RUN_DEPENDS+=	${LOCALBASE}/lib/bwidget/label.tcl:${PORTSDIR}/x11-toolkits/bwidget

NO_BUILD=	yes
MAN1=		tkmerge.1
PLIST_FILES=	bin/tkmerge

NO_STAGE=	yes
.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|wish8.4|${WISH}|g' ${WRKSRC}/tkmerge

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tkmerge ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/tkmerge.1 ${PREFIX}/man/man1

.include <bsd.port.post.mk>
