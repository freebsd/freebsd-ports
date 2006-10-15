# New ports collection makefile for:	xdg-utils
# Date created:		2006-07-02
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/devel/xdg-utils/Makefile,v 1.2 2006/09/02 21:01:28 ahze Exp $
#

PORTNAME=	xdg-utils
PORTVERSION=	1.0
CATEGORIES=	devel
MASTER_SITES=	http://portland.freedesktop.org/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Tools to allow all applications to integrate with the free desktop

GNU_CONFIGURE=	yes
XDG_FILES=	xdg-desktop-icon \
		xdg-desktop-menu \
		xdg-email \
		xdg-icon-resource \
		xdg-mime \
		xdg-open \
		xdg-screensaver

.for file in ${XDG_FILES}
PLIST_FILES+=	bin/${file}
MAN1+=		${file}.1
.endfor

.include <bsd.port.mk>
