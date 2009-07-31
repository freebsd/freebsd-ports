# New ports collection makefile for:	pho
# Date created:				10 April 2003
# Whom:					Roland Jesse <roland.jesse@gmx.net>
#
# $FreeBSD$
#

PORTNAME=	pho
DISTVERSION=	0.9.5.1
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://shallowsky.com/software/pho/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	A lightweight image viewer

USE_GMAKE=	yes
MAKE_ARGS=	INSTALLPREFIX="${PREFIX}"
WANT_GNOME=	yes

OPTIONS=	GTK1 "Build with legacy GTK version (1.2.x)" Off

.include <bsd.port.pre.mk>

.if defined(WITH_GTK1)
USE_GNOME=	gdkpixbuf gtk12
BAD_GTK=	2
.else
USE_GNOME=	gtk20
BAD_GTK=	1
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|make|${GMAKE}|g; \
		s|$$(INSTALL) \(pho \)|${INSTALL_PROGRAM} \1|; \
		s|$$(INSTALL) \(pho.1\)|${INSTALL_MAN} \1|; \
		s|-g -O|${CFLAGS}|; s|pho xpho$$|pho|; \
		s|^G${BAD_GTK}FLAGS|#&|' ${WRKSRC}/Makefile

MAN1=		pho.1
PLIST_FILES=	bin/pho

.include <bsd.port.post.mk>
