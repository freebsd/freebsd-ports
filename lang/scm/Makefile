# New ports collection makefile for:    scm
# Version required:     4e1
# Date created:         Sat Nov  5 17:11:01 PST 1994
# Whom:                 hsu
#
# $Id: Makefile,v 1.1.1.1 1994/11/06 09:59:26 hsu Exp $
#

DISTNAME=       scm
MASTER_SITES=   ftp://swiss-ftp.ai.mit.edu/pub/scm/
DISTFILES=      scm4e1.tar.gz \
		slib.info.tar.gz slib2a1.tar.gz slib-psd1-3.tar.gz \
		scmconfig4e1.tar.gz
GNU_CONFIGURE=
USE_GMAKE=
MAKE_FLAGS=	CFLAGS=-O2 LDFLAGS=-s defines="-DSICP -DHAVE_CONFIG_H -DFLOATS -DIO_EXTENSIONS -DMEMOIZE_LOCALS -DGC_FREE_SEGMENTS" -f

pre-install:
	@if [ ! -e ${PREFIX}/lib ]; then mkdir -p ${PREFIX}/lib; fi
	cp -rp ${WRKDIR}/slib ${PREFIX}/lib
	@if [ ! -e /usr/local/info ]; then mkdir -p /usr/local/info; fi
	(cd ${WRKDIR}/slib; \
		install -c -m 444 slib.info slib.info-1 slib.info-2 \
				  slib.info-3 slib.info-4 /usr/local/info)

.include <bsd.port.mk>
