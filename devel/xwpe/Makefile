# ex:ts=8
# Ports collection makefile for:  xwpe
# Date created:			  Fri Jan 24, 1997
# Whom:				  David O'Brien (obrien@FreeBSD.org)
#
# $FreeBSD$
#

PORTNAME=	xwpe
PORTVERSION=	1.5.29a
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SUNSITE} \
		http://www.identicalsoftware.com/xwpe/ \
		ftp://ftp.identicalsoftware.com/pub/linux/xwpe/
MASTER_SITE_SUBDIR=	apps/editors/X

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Borland-like IDE programming environment

USE_XLIB=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=
CONFIGURE_ARGS=	--libdir=${PREFIX}/share
ALL_TARGET=	# none

MAN1=		xwpe.1
MLINKS=		xwpe.1 xwe.1 \
		xwpe.1 wpe.1 \
		xwpe.1 we.1

post-patch:
.for file in we_prog.c we_fl_unix.c
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g ; \
		 s|%%X11BASE%%|${X11BASE}|g' ${WRKSRC}/${file}
.endfor

.include <bsd.port.mk>
