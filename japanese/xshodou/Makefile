# New ports collection makefile for:   XShodou
# Date created:        11 January 1999
# Whom:                Sakai Hiroaki <sakai@miya.ee.kagu.sut.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	xshodou
PORTVERSION=	1.11
PORTREVISION=	3
CATEGORIES=	japanese tk
MASTER_SITES=	http://www.saturn.dti.ne.jp/~hsakai/myfreesoft/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Japanese shodou program for X based on Tcl/Tk

USE_TK_RUN=	82+

MAN1=		xshodou.1
MANCOMPRESSED=	yes

USE_XORG=	x11

.include <bsd.port.pre.mk>
post-patch:
	@${REINPLACE_CMD} -e 's|/usr/X11R6|${PREFIX}|g' \
		-e 's|/usr/local/bin/wish|${WISH}|g' \
		${WRKSRC}/Makefile ${WRKSRC}/xshodou

.include <bsd.port.post.mk>
