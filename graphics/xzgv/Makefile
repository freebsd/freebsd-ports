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
USE_XORG=	x11
LDFLAGS+=	-L${LOCALBASE}/lib -lX11 -lm

PLIST_FILES=	bin/xzgv man/man1/xzgv.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's|^CC|#CC|g ; \
		 s|^CFLAGS|#CFLAGS|g ; \
		 s|^PREFIX|#PREFIX|g' ${WRKSRC}/config.mk

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/xzgv ${STAGEDIR}${LOCALBASE}/bin/
	${INSTALL_MAN} ${WRKSRC}/doc/xzgv.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
