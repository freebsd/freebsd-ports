# Created by: Sakai Hiroaki <sakai@miya.ee.kagu.sut.ac.jp>
# $FreeBSD$

PORTNAME=	xshodou
PORTVERSION=	1.11
PORTREVISION=	4
CATEGORIES=	japanese tk
MASTER_SITES=	http://kozos.jp/myfreesoft/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Japanese shodou program for X based on Tcl/Tk

USE_TK_WRAPPER=	yes

MANCOMPRESSED=	yes
MAN1=		xshodou.1

NO_STAGE=	yes
post-patch:
.for f in Makefile xshodou
	@${REINPLACE_CMD} -e \
		's|/usr/X11R6|${PREFIX}|g ; \
		 s|/usr/local|${LOCALBASE}|g' ${WRKSRC}/${f}
.endfor

.include <bsd.port.mk>
