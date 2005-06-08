# New ports collection makefile for:	pho
# Date created:				10 April 2003
# Whom:					Roland Jesse <roland.jesse@gmx.net>
#
# $FreeBSD$
#

PORTNAME=	pho
DISTVERSION=	0.9.5-pre3
CATEGORIES=	graphics
MASTER_SITES=	http://shallowsky.com/software/pho/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	A lightweight image viewer

USE_GMAKE=	yes
USE_REINPLACE=	yes
WANT_GNOME=	yes

OPTIONS=	GTK1 "Build with legacy GTK version (1.2.x)" Off

.include <bsd.port.pre.mk>

.if defined(WITH_GTK1)
USE_GNOME=	gdkpixbuf gtk12
.else
USE_GNOME=	gtk20
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|make|${GMAKE}|g; \
		s|$$(INSTALL) \(pho \)|${INSTALL_PROGRAM} \1|; \
		s|$$(INSTALL) \(pho.1\)|${INSTALL_MAN} \1|; \
		s|-g -O2|${CFLAGS}|; s|pho xpho$$|pho|' \
		${WRKSRC}/Makefile
.if defined(WITH_GTK1)
	@${REINPLACE_CMD} -e 's|^G2FLAGS|#&|' ${WRKSRC}/Makefile
.endif

MAN1=		pho.1
PLIST_FILES=	bin/pho

.include <bsd.port.post.mk>
