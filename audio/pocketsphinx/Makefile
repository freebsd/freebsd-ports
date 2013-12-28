# Created by: Richard Neese
# $FreeBSD$

PORTNAME=	pocketsphinx
PORTVERSION=	0.8
CATEGORIES=	audio accessibility
MASTER_SITES=	SF/cmusphinx/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Speech recognition system

LIB_DEPENDS=	libsphinxad.so:${PORTSDIR}/audio/sphinxbase

USES=		gmake pathfix pkgconfig
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool

CONFIGURE_ARGS+=	--without-python
CONFIGURE_ENV+=	HAVE_DOXYGEN=no

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAKE_ENV=	MKDIR="${MKDIR}" \
		OSVERSION=${OSVERSION}

post-patch:
	@${REINPLACE_CMD} -E -e 's|^([[:space:]]+programs )\\$$|\1|;' \
		-e '/[[:space:]]+gst-plugin$$/D;' \
		${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
