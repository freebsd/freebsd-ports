# Ports collection makefile for:  chinput3
# Date created:                          03/31/2002
# Whom:			Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	chinput
PORTVERSION=	3.0.2.5
CATEGORIES=	chinese x11
MASTER_SITES=	ftp://freebsd.sinica.edu.tw/pub/statue/chinput3/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Chinese GB2312,BIG5 code input server

LATEST_LINK=	zh-chinput3
USE_XLIB=	yes
USE_GNOME=	gtk12 imlib

MSG_FILE=	${.CURDIR}/pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

post-install:
	@${SED} -e 's,%%X11BASE%%,${X11BASE},g' ${MSG_FILE} > ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
