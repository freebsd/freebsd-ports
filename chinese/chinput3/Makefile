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

MAINTAINER=	statue@freebsd.sinica.edu.tw
COMMENT=	Chinese GB2312,BIG5 code input server

USE_XLIB=	yes
USE_IMLIB=	yes
USE_GNOME=	gtk12

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500113
BROKEN=         "Does not link"
.endif

port-install:
	@${SED} -e 's,%%X11BASE%%,${X11BASE},g' < ${PKGMESSAGE}

.include <bsd.port.post.mk>
