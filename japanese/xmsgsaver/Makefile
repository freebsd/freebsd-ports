# New ports collection makefile for:	xmsgsaver
# Date created:		8 March 2000
# Whom:			Tatsuya Kudoh (CDR/TK)
#
# $FreeBSD$
#

PORTNAME=	xmsgsaver
PORTVERSION=	1.8.1
PORTREVISION=	4
CATEGORIES=	japanese
MASTER_SITES=	http://www19.xdsl.ne.jp/~cdr/soft/dl/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An X11 screensaver using VFlib

LIB_DEPENDS=	VFlib2.24:${PORTSDIR}/japanese/vflib

MAN1=		xmsgsaver.1
USE_IMAKE=	yes
USE_XORG=	ice sm x11 xaw xext xmu xpm xscrnsaver xt

.include <bsd.port.mk>
