# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	adgali
PORTVERSION=	0.2.4
PORTREVISION=	11
CATEGORIES=	games devel
MASTER_SITES=	http://adgali.apiou.org/download/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Open source game library useful for 2D game development

LICENSE=	GPLv2

LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libpng15.so:${PORTSDIR}/graphics/png \
		libtiff.so:${PORTSDIR}/graphics/tiff \
		libfreetype.so:${PORTSDIR}/print/freetype2
.if !exists(/usr/include/execinfo.h)
LIB_DEPENDS+=	libexecinfo.so:${PORTSDIR}/devel/libexecinfo
.endif

USES=		gmake
USE_AUTOTOOLS=	libtool
USE_BZIP2=	yes
USE_LDCONFIG=	yes
USE_SDL=	sdl
USE_XORG=	xpm
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-compile-optim=no

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lexecinfo

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc/html && ${FIND} . | ${CPIO} -pdm -L -R \
		${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
