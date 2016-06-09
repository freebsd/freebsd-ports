# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	adgali
PORTVERSION=	0.2.4
PORTREVISION=	15
CATEGORIES=	games devel
MASTER_SITES=	http://www.sourcefiles.org/Programming/Libraries/Games/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open source game library useful for 2D game development

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:graphics/png \
		libtiff.so:graphics/tiff \
		libfreetype.so:print/freetype2

USES=		execinfo gmake jpeg libtool tar:bzip2
USE_LDCONFIG=	yes
USE_SDL=	sdl
USE_XORG=	xpm
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-compile-optim=no
INSTALL_TARGET=	install-strip

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lexecinfo

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc/html && ${FIND} . | ${CPIO} -pdm -L -R \
		${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
