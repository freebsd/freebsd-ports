# New ports collection makefile for:	MicroEmacs
# Version required:     3.12
# Date created:         16 Jan 1995
# Whom:                 thomas@ghpc8.ihf.rwth-aachen.de
#

DISTNAME=	uemacs
MASTER_SITES=	ftp://midas.mgmt.purdue.edu/pub/ue312/
PATCH_STRIP=	-p1
DISTFILES=	ue312dev.zip
EXEC_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

# one weakness of the ports scheme: it doesn't allow arguments
# to ${EXTRACT_CMD} after the filename, which is required for unzip.

NO_WRKSUBDIR=	yes

pre-extract: exec_depends
	@echo "===>  Extracting for ${DISTNAME}"
	@rm -rf ${WRKDIR}
	@mkdir -p ${WRKDIR}
	@unzip -Laq ${DISTDIR}/${DISTFILES} -d ${WRKDIR}

extract: fetch pre-extract ${EXTRACT_COOKIE}
	@${TOUCH} ${TOUCH_FLAGS} ${EXTRACT_COOKIE}

.include <bsd.port.mk>
