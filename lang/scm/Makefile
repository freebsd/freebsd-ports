# New ports collection makefile for:    scm
# Version required:     4e1
# Date created:         Sat Nov  5 17:11:01 PST 1994
# Whom:                 hsu
#
# $Id: Makefile,v 1.13 1998/08/10 12:11:42 steve Exp $
#

DISTNAME=       scm
PKGNAME=	scm-4e1
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.cs.oswego.edu/pub/Z/unix/scheme/ \
		ftp://ftp.swiss.ai.mit.edu/pub/scm/ \
		ftp://ftp.swiss.ai.mit.edu/pub/scm/OLD/
DISTFILES=      scm4e1.tar.gz slib.info.tar.gz slib2a2.tar.gz \
		slib-psd1-3.tar.gz scmconfig4e1.tar.gz

MAINTAINER=	ports@FreeBSD.org

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
MAKE_FLAGS=	CFLAGS=-O2 LDFLAGS=-s defines="-DSICP -DHAVE_CONFIG_H -DFLOATS -DIO_EXTENSIONS -DMEMOIZE_LOCALS -DGC_FREE_SEGMENTS" -f
MAN1=		scm.1

pre-install:
	${MKDIR} ${PREFIX}/lib/slib/psd
	${INSTALL_DATA} ${WRKDIR}/slib/*.scm ${PREFIX}/lib/slib
	${INSTALL_DATA} ${WRKDIR}/slib/psd/*.scm ${PREFIX}/lib/slib/psd
	(cd ${WRKDIR}/slib; \
		makeinfo slib.texi; \
		${INSTALL_MAN} slib.info slib.info-1 slib.info-2 \
			  slib.info-3 slib.info-4 ${PREFIX}/info)

.include <bsd.port.mk>
