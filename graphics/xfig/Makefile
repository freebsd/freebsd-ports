# Created by: roberto
# $FreeBSD$

PORTNAME=	xfig
PORTVERSION=	3.2.7a
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF/mcj/

MAINTAINER=	mjl@luckie.org.nz
COMMENT=	Drawing program for X11

LIB_DEPENDS=	libpng.so:graphics/png \
		libXaw3d.so:x11-toolkits/Xaw3d
RUN_DEPENDS=	fig2dev:print/fig2dev

USES=		desktop-file-utils gmake jpeg localbase:ldflags \
		tar:xz xorg

CONFLICTS=	xfig-[12].* xfig-3.1* xfig-3.2.[1234]*
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
GNU_CONFIGURE=	yes
USE_XORG=	ice sm x11 xaw xext xi xmu xpm xt
USE_CSTD=	gnu89
CFLAGS+=	-Wno-return-type

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/||' ${WRKSRC}/xfig.desktop

.include <bsd.port.mk>
