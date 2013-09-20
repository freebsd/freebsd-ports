# Created by: chinsan
# $FreeBSD$

PORTNAME=	scale2x
PORTVERSION=	3.0
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Real-time graphics effect able to increase the size of small bitmaps

LICENSE=	GPLv2 # (or later)

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png

OPTIONS_DEFINE=	DOCS EXAMPLES
OPTIONS_DEFINE_i386=	MMX

GNU_CONFIGURE=	yes

CPPFLAGS+=	$$(libpng15-config --I_opts)
LDFLAGS+=	$$(libpng15-config --L_opts)

MAN1=		scalex.1 scalerx.1
PORTDOCS=	*
PORTEXAMPLES=	*
PLIST_FILES=	bin/scalex bin/scalerx

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMMX}
CPPFLAGS+=	-DHAVE_MMX
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/<malloc.h>/d ; \
		 s|__i386__|HAVE_MMX| ; \
		 s|__x86_64__|__amd64__|' ${WRKSRC}/*.[ch]

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} *.html ${DOCSDIR})
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	(cd ${WRKSRC}/example && ${INSTALL_DATA} *.png ${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
