DISTFILES=      iozone-2.01.shar.gz
DISTNAME=       iozone
MASTER_SITES=   ftp://ftp.cs.uni-sb.de/pub/others/
EXTRACT_CMD=    ( gzcat | /usr/local/bin/gunshar )
EXTRACT_ARGS=   <
NO_WRKSUBDIR=   YES
EXEC_DEPENDS=   gunshar:${PORTSDIR}/archivers/gshar+gunshar

pre-extract: depends

.include <bsd.port.mk>
