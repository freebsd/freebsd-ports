# Created by: Richard Neese
# $FreeBSD$

PORTNAME=	pocketsphinx
PORTVERSION=	0.7
CATEGORIES=	audio accessibility
MASTER_SITES=	SF/cmusphinx/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Speech recognition system

LIB_DEPENDS=	sphinxad:${PORTSDIR}/audio/sphinxbase

USE_LDCONFIG=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
USE_PKGCONFIG=	build

CONFIGURE_ARGS+=	--without-python
CONFIGURE_ENV+=	HAVE_DOXYGEN=no

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAKE_ENV=	MKDIR="${MKDIR}" \
		OSVERSION=${OSVERSION}

MAN1=	pocketsphinx_batch.1 \
	pocketsphinx_continuous.1 \
	pocketsphinx_mdef_convert.1

post-patch:
	@${REINPLACE_CMD} -e 's|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -E -e 's|^([[:space:]]+programs )\\$$|\1|;' \
		-e '/[[:space:]]+gst-plugin$$/D;' \
		${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
