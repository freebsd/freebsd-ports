# Created by: Norio Suzuki <nosuzuki@e-mail.ne.jp>
# $FreeBSD$

PORTNAME=	xzgv
PORTVERSION=	0.9
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	nosuzuki@postcard.st
COMMENT=	Image viewer with thumbnail-based file selector for X

BUILD_DEPENDS=  gawk:${PORTSDIR}/lang/gawk

USES=		gmake pkgconfig
USE_GNOME=	imlib gdkpixbuf gtk20

MAN1=		xzgv.1
PLIST_FILES=	bin/xzgv

NO_STAGE=	yes
.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|^CC|#CC|g ; \
		 s|^CFLAGS|#CFLAGS|g ; \
		 s|^PREFIX|#PREFIX|g' ${WRKSRC}/config.mk

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/xzgv ${LOCALBASE}/bin/
	${INSTALL_MAN} ${WRKSRC}/doc/xzgv.1 ${MANPREFIX}/man/man1

.include <bsd.port.post.mk>
