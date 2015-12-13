# Created by: Piotr Smyrak <smyru@heron.pl>
# $FreeBSD$

PORTNAME=	potrace
PORTVERSION=	1.11
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	ps.ports@smyrak.com
COMMENT=	Transforms bitmaps into vector graphics

BROKEN=		unfetchable
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/potrace bin/mkbitmap \
		man/man1/potrace.1.gz \
		man/man1/mkbitmap.1.gz

OPTIONS_DEFINE=	METRIC A4
OPTIONS_DEFAULT=METRIC A4

METRIC_DESC=	Use metric units (cm) as default
A4_DESC=	Use A4 as the default papersize

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MA4}
CONFIGURE_ARGS+=	--enable-a4
.endif

.if ${PORT_OPTIONS:MMETRIC}
CONFIGURE_ARGS+=	--enable-metric
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/potrace ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/mkbitmap ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/potrace.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/mkbitmap.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
