# $FreeBSD$

PORTNAME=	sd-mux
PORTVERSION=	g20201028
CATEGORIES=	devel
MASTER_SITES=	LOCAL/swills
DISTNAME=	sd-mux-20201028

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Utility for controlling sd-mux and sd-wire

LIB_DEPENDS=	libftdi1.so:devel/libftdi1 \
		libpopt.so:devel/popt

USES=		cmake pkgconfig

PLIST_FILES=	bin/sd-mux-ctrl \
		man/man1/sd-mux-ctrl.1.gz

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/man/sd-mux-ctrl.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
