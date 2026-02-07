PORTNAME=	largetifftools
PORTVERSION=	1.4.2
CATEGORIES=	graphics
MASTER_SITES=	https://pperso.ijclab.in2p3.fr/page_perso/Deroulers/software/largetifftools/download/${PORTNAME}-${PORTVERSION}/ \
		LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Process very large TIFF files
WWW=		https://pperso.ijclab.in2p3.fr/page_perso/Deroulers/software/largetifftools/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:graphics/png \
		libtiff.so:graphics/tiff \
		libzstd.so:archivers/zstd

USES=		autoreconf jpeg localbase:ldconfig tar:bzip2
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
