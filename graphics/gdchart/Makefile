# Created by: Anders Nordby <anders@fix.no>
# $FreeBSD$

PORTNAME=	gdchart
PORTVERSION=	0.11.5
PORTREVISION=	10
CATEGORIES=	graphics
MASTER_SITES=	http://www.fred.net/brv/chart/ \
		ftp://ftp.nuug.no/pub/anders/distfiles/
DISTNAME=	${PORTNAME}${PORTVERSION}dev

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Easy to use fast C API for creating charts and graphs

LIB_DEPENDS=	libgd.so:graphics/gd \
		libfreetype.so:print/freetype2

USES=		jpeg uidfix
MAKEFILE=	${FILESDIR}/Makefile
MAKE_ARGS=	PREFIX="${PREFIX}" LOCALBASE="${LOCALBASE}"
USE_LDCONFIG=	yes

PORTDOCS=	README.txt
PORTEXAMPLES=	ft_samp.c gdc_pie_samp.c gdc_samp1.c gdc_samp2.c

.if defined(NO_PROFILE)
PLIST_SUB+=	PROFILE="@comment "
.else
PLIST_SUB+=	PROFILE=""
.endif

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} \
		-e 's/^#ifdef HAVE_JPEG/#ifndef NO_JPEG/' \
		-e 's/^#ifdef HAVE_LIBFREETYPE/#ifndef NO_LIBFREETYPE/' \
			${WRKSRC}/*.[ch]
# ft_samp.c and gdc_samp?.c miss #include "gdcpie.h"
	@${REINPLACE_CMD} \
		-e 's/^#include "gdc\.h"/#include "gdcpie.h"/' \
			${WRKSRC}/ft_samp.c \
			${WRKSRC}/gdc_samp?.c
# gdc_pie_samp.c misses #include "gdchart.h"
	@${REINPLACE_CMD} \
		-e 's/^#include "gdc\.h"/#include "gdchart.h"/' \
			${WRKSRC}/gdc_pie_samp.c

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S|^|${WRKSRC}/|} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
