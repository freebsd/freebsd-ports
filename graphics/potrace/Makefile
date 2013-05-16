# Created by: Piotr Smyrak <smyru@heron.pl>
# $FreeBSD$

PORTNAME=	potrace
PORTVERSION=	1.11
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	ps.ports@smyrak.com
COMMENT=	Transforms bitmaps into vector graphics

GNU_CONFIGURE=	yes

.if !defined(NO_INSTALL_MANPAGES)
MAN1=		potrace.1 mkbitmap.1
.endif
PLIST_FILES=	bin/potrace bin/mkbitmap

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
	${INSTALL_PROGRAM} ${WRKSRC}/src/potrace ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/mkbitmap ${PREFIX}/bin
.if !defined(NO_INSTALL_MANPAGES)
	${INSTALL_MAN} ${WRKSRC}/doc/potrace.1 ${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/mkbitmap.1 ${MAN1PREFIX}/man/man1
.endif

.include <bsd.port.mk>
