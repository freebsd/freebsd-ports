# New ports collection makefile for:   XShodou
# Date created:        11 January 1999
# Whom:                Sakai Hiroaki <sakai@miya.ee.kagu.sut.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	xshodou
PORTVERSION=	1.11
CATEGORIES=	japanese tk80
MASTER_SITES=	http://www.saturn.dti.ne.jp/~hsakai/myfreesoft/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Japanese shodou program for X based on Tcl/Tk

RUN_DEPENDS=	wish8.0:${PORTSDIR}/x11-toolkits/tk80

USE_X_PREFIX=	yes

MAN1=		xshodou.1
MANCOMPRESSED=	yes

WISH=		${LOCALBASE}/bin/wish8.0

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/X11R6|${PREFIX}|g' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e \
		's|/usr/local/bin/wish|${WISH}|g' ${WRKSRC}/xshodou

.include <bsd.port.mk>
