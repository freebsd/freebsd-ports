DISTFILES=      iozone-2.01.shar.gz
DISTNAME=       iozone
MASTER_SITES=   ftp://ftp.cs.uni-sb.de/pub/others/
CATEGORIES+=	utilities
EXTRACT_CMD=    ( gzcat | /usr/local/bin/gunshar )
EXTRACT_ARGS=   <
NO_WRKSUBDIR=   YES
EXEC_DEPENDS=   gunshar:${PORTSDIR}/archivers/gshar+gunshar
MAINTAINER=	jmz@FreeBSD.org

pre-extract: depends

.include <bsd.port.mk>
