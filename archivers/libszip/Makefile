PORTNAME=	libszip
DISTVERSION=	2.1.1
CATEGORIES=	archivers
MASTER_SITES=	https://support.hdfgroup.org/ftp/lib-external/szip/${DISTVERSION}/src/
DISTNAME=	szip-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Implementation of the extended-Rice lossless compression algorithm
WWW=		https://support.hdfgroup.org/

LICENSE=	SZIP
LICENSE_NAME=	SZIP Copyright and License Notice
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	auto-accept dist-mirror pkg-mirror # scientific use only is allowed [...] in conjunction with HDF data storage and retrieval file format and software library products (HDF5)

USES=		cmake:testing

CONFLICTS_INSTALL=	libaec

.include <bsd.port.mk>
