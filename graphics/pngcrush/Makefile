PORTNAME=	pngcrush
PORTVERSION=	1.8.13
CATEGORIES=	graphics
MASTER_SITES=	SF/pmt/${PORTNAME}/${PORTVERSION}/ \
		SF/pmt/${PORTNAME}/old-versions/${PORTVERSION:R}/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-nolib

MAINTAINER=	vsasjason@gmail.com
COMMENT=	Optimizer for PNG files
WWW=		http://pmt.sourceforge.net/pngcrush/

LICENSE=	Pngcrush
LICENSE_NAME=	Pngcrush License
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

BROKEN=		Depends on undocumented feature to disable Adler32 checksums, consider graphics/oxipng or graphics/pngquant
EXPIRATION_DATE=2024-02-29

LIB_DEPENDS=	libpng.so:graphics/png

USES=		cpe localbase:ldflags tar:xz
MAKE_ARGS+=	CC="${CC}" CFLAGS="${CFLAGS}" CPPFLAGS="${CPPFLAGS}" LD="${CC}" \
		LDFLAGS="${LDFLAGS}"

CPE_VENDOR=	pngcrush_project

PLIST_FILES=	bin/pngcrush

post-patch:
	@${REINPLACE_CMD} -e '/^LIBS/s|-L$$([[:alnum:]]*) ||g' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/pngcrush

.include <bsd.port.mk>
