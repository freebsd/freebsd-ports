PORTNAME=	lzip
DISTVERSION=	1.25
CATEGORIES=	archivers
MASTER_SITES=	SAVANNAH/lzip

MAINTAINER=	gerald@FreeBSD.org
COMMENT=	Lossless data compressor based on the LZMA algorithm
WWW=		https://www.nongnu.org/lzip/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	CXX="${CXX}" \
		CXXFLAGS="${CXXFLAGS}" \
		LDFLAGS="${LDFLAGS}"
INSTALL_TARGET=	install-strip

INFO=		lzip
PLIST_FILES=	bin/lzip \
		share/man/man1/lzip.1.gz

.include <bsd.port.mk>
