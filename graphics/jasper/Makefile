# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jasper
PORTVERSION=	1.900.1
PORTREVISION=	16
CATEGORIES=	graphics
MASTER_SITES=	http://www.ece.uvic.ca/~mdadams/jasper/software/ \
		ftp://ftp.imagemagick.org/pub/ImageMagick/delegates/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Implementation of the codec specified in the JPEG-2000 standard

LICENSE=	MIT

USES=		zip libtool:keepla jpeg
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--enable-shared --enable-static
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	OPENGL UUID DOCS
OPTIONS_DEFAULT=UUID
UUID_DESC=	UUID support (required by GDAL)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPENGL}
USE_XORG=	x11 xmu xi xext
USE_GL=		glut
CONFIGURE_ARGS+=--enable-opengl
PLIST_SUB+=	OPENGL=""
.else
CONFIGURE_ARGS+=--disable-opengl
PLIST_SUB+=	OPENGL="@comment "
.endif

.if ${PORT_OPTIONS:MUUID}
EXTRA_PATCHES+=	${FILESDIR}/uuid.patch
.endif

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
