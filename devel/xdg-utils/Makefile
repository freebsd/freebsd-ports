# New ports collection makefile for:	xdg-utils
# Date created:		2006-07-02
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports-stable/devel/xdg-utils/Makefile,v 1.1 2006/10/27 20:43:38 ahze Exp $
#

PORTNAME=	xdg-utils
PORTVERSION=	1.0.2
PORTREVISION=	4
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

PLIST_FILES+=	${XDG_FILES:S|^|bin/|}
MAN1+=		${XDG_FILES:S|$|.1|}

pre-patch:
	@${RM} -f ${WRKSRC}/*/*.orig

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/scripts/xdg-*

.include <bsd.port.mk>
