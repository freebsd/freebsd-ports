# Created by: chinsan
# $FreeBSD$

PORTNAME=	scale2x
PORTVERSION=	3.1
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Real-time graphics effect able to increase the size of small bitmaps

LICENSE=	GPLv2+

LIB_DEPENDS=	libpng.so:graphics/png

GNU_CONFIGURE=	yes

CPPFLAGS+=	$$(libpng-config --I_opts)
LDFLAGS+=	$$(libpng-config --L_opts)

PORTEXAMPLES=	*
PLIST_FILES=	bin/scalex bin/scalerx \
		man/man1/scalex.1.gz man/man1/scalerx.1.gz

OPTIONS_DEFINE=		EXAMPLES
OPTIONS_DEFINE_i386=	MMX

MMX_CPPFLAGS=		-DHAVE_MMX

post-patch:
	@${REINPLACE_CMD} -e \
		'/<malloc.h>/d ; \
		 s|__i386__|HAVE_MMX| ; \
		 s|__x86_64__|__amd64__|' ${WRKSRC}/*.[ch]

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/example && ${INSTALL_DATA} *.png \
		${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
