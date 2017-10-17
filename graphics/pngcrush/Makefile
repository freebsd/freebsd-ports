# Created by: Chris D. Faulhaber <jedgar@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pngcrush
PORTVERSION=	1.8.13
CATEGORIES=	graphics
MASTER_SITES=	SF/pmt/${PORTNAME}/${PORTVERSION}/ \
		SF/pmt/${PORTNAME}/old-versions/${PORTVERSION:R}/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-nolib

MAINTAINER=	vsasjason@gmail.com
COMMENT=	Optimizer for PNG files

LICENSE=	Pngcrush
LICENSE_NAME=	Pngcrush License
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

LIB_DEPENDS=	libpng.so:graphics/png

USES=		localbase:ldflags tar:xz
MAKE_ARGS+=	CC="${CC}" CFLAGS="${CFLAGS}" CPPFLAGS="${CPPFLAGS}" LD="${CC}" \
		LDFLAGS="${LDFLAGS}"

PLIST_FILES=	bin/pngcrush

post-patch:
	@${REINPLACE_CMD} -e '/^LIBS/s|-L$$([[:alnum:]]*) ||g' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/pngcrush

.include <bsd.port.mk>
