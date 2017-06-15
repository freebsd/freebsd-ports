# Created by: Piotr Smyrak <smyru@heron.pl>
# $FreeBSD$

PORTNAME=	potrace
PORTVERSION=	1.14
CATEGORIES=	graphics
MASTER_SITES=	http://sourceforge.net/projects/potrace/files/${PORTVERSION}/

MAINTAINER=	ps.ports@smyrak.com
COMMENT=	Transforms bitmaps into vector graphics

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/potrace bin/mkbitmap \
		man/man1/potrace.1.gz \
		man/man1/mkbitmap.1.gz

OPTIONS_DEFINE=	METRIC A4
OPTIONS_DEFAULT=METRIC A4

METRIC_DESC=	Use metric units (cm) as default
METRIC_CONFIGURE_ENABLE=	metric
A4_DESC=	Use A4 as the default papersize
A4_CONFIGURE_ENABLE=	a4

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/potrace ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/mkbitmap ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/potrace.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/mkbitmap.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
