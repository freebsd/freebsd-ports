# New ports collection makefile for:   pho
# Date created:        10 April 2003
# Whom:                Roland Jesse <roland.jesse@gmx.net>
#
# $FreeBSD$
#

PORTNAME=	pho
PORTVERSION=	0.9.2
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://shallowsky.com/software/pho/

MAINTAINER=	roland.jesse@gmx.net
COMMENT=	A lightweight image viewer

USE_GMAKE=	yes
USE_GNOME=	gdkpixbuf gtk12
USE_REINPLACE=	yes

MAN1=		pho.1

post-patch:
	@${REINPLACE_CMD} -e 's|make|${GMAKE}|g; \
		s|$$(INSTALL) \(pho \)|${INSTALL_PROGRAM} \1|; \
		s|$$(INSTALL) \(pho.1\)|${INSTALL_MAN} \1|; \
		s|-g -O2|${CFLAGS}|' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
