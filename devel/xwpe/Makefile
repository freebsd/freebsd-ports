# ex:ts=8
# Ports collection makefile for:  xwpe
# Date created:			  Fri Jan 24, 1997
# Whom:				  David O'Brien (obrien@FreeBSD.org)
#
# $FreeBSD$
#

PORTNAME=	xwpe
PORTVERSION=	1.5.22a
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SUNSITE} \
		http://www.identicalsoftware.com/xwpe/ \
		ftp://ftp.identicalsoftware.com/pub/linux/xwpe/
MASTER_SITE_SUBDIR=	apps/editors/X

MAINTAINER=	obrien@FreeBSD.org

# LD_LIBRARY_PATH is to deal with a braindead libX11.a search in configure
# (once again author assumes too many Linux'isms)
# it is not exptected to be set at runtime.
MAKE_ENV=	LD_LIBRARY_PATH="${X11BASE}/lib"
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LD_LIBRARY_PATH="${X11BASE}/lib"
CONFIGURE_ARGS=	--libdir=${PREFIX}/share
USE_XLIB=	yes
USE_GMAKE=	yes
ALL_TARGET=
MAN1=		xwpe.1
MLINKS=		xwpe.1 xwe.1 \
		xwpe.1 wpe.1 \
		xwpe.1 we.1

pre-configure:
	@${PERL} -pi.in -e "s:%%LOCALBASE%%:${LOCALBASE}:g" ${WRKSRC}/*.c

.include <bsd.port.mk>
