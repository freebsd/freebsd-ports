DISTFILES= 1587.Z 1588.Z 1589.Z
MASTER_SITES=   ftp://src.doc.ic.ac.uk/usenet/alt.sources/articles/
DISTNAME=       g3view
EXTRACT_CMD=    (cd ${WRKDIR}; gzcat | awk '{if (/^\#!/) x++} {if(x) print $$0'}| /bin/sh)
EXTRACT_ARGS=   <
NO_WRKSUBDIR=   YES

pre-install:
	@mkdir -p ${PREFIX}/bin
	@mkdir -p ${PREFIX}/man/man1

.include <bsd.port.mk>
