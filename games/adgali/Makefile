# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	adgali
PORTVERSION=	0.2.4
PORTREVISION=	15
CATEGORIES=	games devel
MASTER_SITES=	http://adgali.apiou.org/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open source game library useful for 2D game development

LICENSE=	GPLv2

LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libpng.so:${PORTSDIR}/graphics/png \
		libtiff.so:${PORTSDIR}/graphics/tiff \
		libfreetype.so:${PORTSDIR}/print/freetype2

USES=		execinfo gmake libtool tar:bzip2
USE_LDCONFIG=	yes
USE_SDL=	sdl
USE_XORG=	xpm
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-compile-optim=no

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lexecinfo

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc/html && ${FIND} . | ${CPIO} -pdm -L -R \
		${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
