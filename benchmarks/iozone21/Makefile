DISTFILES=      iozone-2.01.shar.gz
DISTNAME=       iozone
MASTER_SITES=   ftp://ftp.cs.uni-sb.de/pub/others/
EXTRACT_CMD=    cd ${WRKDIR}; (gzcat | /usr/local/bin/gunshar)
EXTRACT_ARGS=   <
NO_WRKSUBDIR=   YES
DEPENDS=        ${PORTSDIR}/utils/gshar+gunshar

pre-extract: depends

.include <bsd.port.mk>
