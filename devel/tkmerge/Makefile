# New ports collection makefile for:	tkmerge
# Date created:         16 Dec 2004
# Whom:			Bob Willcox <bob@immure.com>
#
# $FreeBSD$
#

PORTNAME=	tkmerge
PORTVERSION=	0.81
CATEGORIES=	devel tk84
MASTER_SITES=	http://immure.com/~bob/ports/tkmerge/

MAINTAINER=	bob@immure.com
COMMENT=	A tk script to aid in the merging changes between two files

RUN_DEPENDS=	wish8.4:${PORTSDIR}/x11-toolkits/tk84 \
		${LOCALBASE}/lib/bwidget/label.tcl:${PORTSDIR}/x11-toolkits/bwidget

NO_BUILD=	yes
MAN1=		tkmerge.1
PLIST_FILES=	bin/tkmerge

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tkmerge ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/tkmerge.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
