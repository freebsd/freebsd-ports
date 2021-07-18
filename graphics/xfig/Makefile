# Created by: roberto

PORTNAME=	xfig
PORTVERSION=	3.2.8a
CATEGORIES=	graphics
MASTER_SITES=	SF/mcj/

MAINTAINER=	mjl@luckie.org.nz
COMMENT=	Drawing program for X11

LICENSE=	xfig
LICENSE_NAME=	xfig public license
LICENSE_FILE=	${FILESDIR}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libgs.so:print/ghostscript9-agpl-base \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff \
		libXaw3d.so:x11-toolkits/Xaw3d
RUN_DEPENDS=	fig2dev:print/fig2dev

USES=		desktop-file-utils gmake jpeg localbase:ldflags tar:xz xorg
USE_CSTD=	gnu89
USE_XORG=	ice sm x11 xaw xext xi xmu xpm xt

GNU_CONFIGURE=	yes
CFLAGS+=	-Wno-return-type

CONFLICTS=	xfig-3.1* xfig-3.2.[1234]* xfig-[12].*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/||' ${WRKSRC}/xfig.desktop

.include <bsd.port.mk>
