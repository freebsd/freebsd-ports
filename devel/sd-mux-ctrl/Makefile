PORTNAME=	sd-mux-ctrl
DISTVERSION=	g20200217
CATEGORIES=	devel
MASTER_SITES=	https://git.tizen.org/cgit/tools/testlab/sd-mux/snapshot/sd-mux-9dd189d973da64e033a0c5c2adb3d94b23153d94.tar.bz2?/

PATCH_SITES=	https://github.com/emaste/sd-mux/commit/
PATCHFILES=	83f2783ac56bbf42f9bb877c5937cd1f17bb2999.patch:-p1

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Control utility for Tizen SD card multiplexer

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libftdi1.so:devel/libftdi1 \
		libpopt.so:devel/popt

USES=		cmake pkgconfig tar:bz2

WRKSRC=		${WRKDIR}/sd-mux-9dd189d973da64e033a0c5c2adb3d94b23153d94

PLIST_FILES=	bin/sd-mux-ctrl \
		man/man1/sd-mux-ctrl.1.gz

post-install:
		${INSTALL_MAN} ${WRKSRC}/doc/man/sd-mux-ctrl.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
