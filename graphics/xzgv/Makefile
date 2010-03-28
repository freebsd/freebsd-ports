# New ports collection makefile for:	xzgv
# Date created:				7 Oct 2000
# Whom:					Norio Suzuki <nosuzuki@e-mail.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	xzgv
PORTVERSION=	0.9
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	nosuzuki@postcard.st
COMMENT=	An image viewer with thumbnail-based file selector for X

BUILD_DEPENDS=  gawk:${PORTSDIR}/lang/gawk

USE_GNOME=	imlib gdkpixbuf gtk20
USE_GMAKE=	yes

MAN1=		xzgv.1
PLIST_FILES=	bin/xzgv

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|^CC|#CC|g ; \
		 s|^CFLAGS|#CFLAGS|g ; \
		 s|^PREFIX|#PREFIX|g' ${WRKSRC}/config.mk

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/xzgv ${LOCALBASE}/bin/
	${INSTALL_MAN} ${WRKSRC}/doc/xzgv.1 ${MANPREFIX}/man/man1

.include <bsd.port.post.mk>
