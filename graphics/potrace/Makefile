# Ports collection makefile for:	potrace
# Date created:				24 September 2003
# Whom:					Piotr Smyrak <smyru@heron.pl>
#
# $FreeBSD$
#

PORTNAME=	potrace
PORTVERSION=	1.3
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://potrace.sourceforge.net/download/

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	${PORTNAME}-${PORTVERSION}-speed.patch
PATCH_DIST_STRIP=	-p1

MAINTAINER=	smyru@heron.pl
COMMENT=	Transforms bitmaps into vector graphics

GNU_CONFIGURE=	yes

MAN1=		potrace.1 mkbitmap.1

.if defined(A4)
CONFIGURE_ARGS+=	--enable-a4
.endif

.if defined(WITH_LZW) || defined(HAVE_UNISYS_LICENSE) || defined(WITH_GIF_LZW_COMPRESSION)
CONFIGURE_ARGS+=	--enable-compress
.else
CONFIGURE_ARGS+=	--disable-compress
.endif

.if defined(WITH_METRIC)
CONFIGURE_ARGS+=	--enable-metric
.endif

PORTDOCS=	potrace.ps potrace.pdf

pre-everything::
	@${ECHO} ""
	@${ECHO} "You may define the following build options:"
	@${ECHO} ""
	@${ECHO} "    WITH_LZW         Enable patented external LZW compression"
	@${ECHO} "    WITH_METRIC      Enable use of metric units (centimeters) as default"
	@${ECHO} "    A4               Enable use of A4 as the default papersize"
	@${ECHO} ""

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
