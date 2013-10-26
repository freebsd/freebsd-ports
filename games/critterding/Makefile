# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	critterding
DISTVERSION=	beta12
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/sources

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Evolving Artificial Life

LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2

USE_BZIP2=	yes
USES=		pkgconfig
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf:env aclocal:env automake:env libtool
USE_SDL=	sdl
USE_GL=		gl
CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/freetype2
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-system-ftgl
USE_GCC=	yes

PORTDOCS=	README AUTHORS Changelog

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|../share/critterding|${DATADIR}|' \
		${WRKSRC}/src/gui/textprinter.cpp ${WRKSRC}/src/gl/glwindow.cpp

pre-configure:
	cd ${WRKSRC} && ${AUTORECONF} -fi

.if ${PORT_OPTIONS:MDOCS}
post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
