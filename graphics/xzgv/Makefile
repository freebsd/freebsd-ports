# New ports collection makefile for:	xzgv
# Date created:				7 Oct 2000
# Whom:					Norio Suzuki <nosuzuki@e-mail.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	xzgv
PORTVERSION=	0.8
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://xzgv.browser.org/ \
		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/graphics/viewers/X

MAINTAINER=	nosuzuki@postcard.st
COMMENT=	An image viewer with thumbnail-based file selector for X

USE_X_PREFIX=	yes
USE_GNOME=	imlib
USE_REINPLACE=	yes
USE_GMAKE=	yes

MAN1=		xzgv.1
INFO=		xzgv
PLIST_FILES=	bin/xzgv

post-patch:
	@${REINPLACE_CMD} -e 's|^CC|#CC|g ; \
		 s|^CFLAGS|#CFLAGS|g ; \
		 s|^PREFIX|#PREFIX|g' ${WRKSRC}/config.mk

.include <bsd.port.pre.mk>

.if defined(WITH_MMX) && (${ARCH} == "i386")
CFLAGS+=	-DINTERP_MMX
.endif

.include <bsd.port.post.mk>
