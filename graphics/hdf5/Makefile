# New ports collection makefile for:	HDF_lib
# Version required:	4.1r2
# Date created:		17 November 1996
# Whom:			mi
#
# $Id: Makefile,v 1.3 1998/04/08 12:53:43 tg Exp $
#

DISTNAME=	HDF4.1r2
PKGNAME=	hdf-4.1r2
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.ncsa.uiuc.edu/HDF/HDF4.1r2/tar/

MAINTAINER=	mi@aldan.ziplink.net

LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg

GNU_CONFIGURE=	yes
FC?=		f77 # Can also be g77 for the newer one
MAKE_FLAGS=	CC="$(CC)" FC="${FC}" -f

# This will create dummy Makefiles and some links in the jpeg and libz
# subdirectories. This way, we do not need to hunt all the dependencies
# out. Shame on the lib's developers, though, this can not be done through
# `configure'.	-mi
pre-build:
	test -d ${WRKSRC}/hdf/jpeg.came-with-HDF || \
		${MV} -f ${WRKSRC}/hdf/jpeg ${WRKSRC}/hdf/jpeg.came-with-HDF
	-${MKDIR} ${WRKSRC}/hdf/jpeg
	${RM} -f ${WRKSRC}/hdf/jpeg/Makefile
	${ECHO} #Phony makefile > ${WRKSRC}/hdf/jpeg/Makefile
	${ECHO} >> ${WRKSRC}/hdf/jpeg/Makefile
	${ECHO} libjpeg.a: >> ${WRKSRC}/hdf/jpeg/Makefile
	printf '\t@echo Using the already installed JPEG library\n' \
		>> ${WRKSRC}/hdf/jpeg/Makefile
	printf '\nclean:\n\ttrue\n' >> ${WRKSRC}/hdf/jpeg/Makefile
	printf '\ninstall-lib:\n\ttrue\n' >> ${WRKSRC}/hdf/jpeg/Makefile
	printf '\ninstall:\n\ttrue\n' >> ${WRKSRC}/hdf/jpeg/Makefile
	-ln -s ${PREFIX}/lib/libjpeg* ${WRKSRC}/hdf/jpeg/
	-ln -s ${PREFIX}/include/j*.h ${WRKSRC}/hdf/jpeg/
	test -d ${WRKSRC}/hdf/zlib.came-with-HDF || \
		${MV} -f ${WRKSRC}/hdf/zlib ${WRKSRC}/hdf/zlib.came-with-HDF
	-${MKDIR} ${WRKSRC}/hdf/zlib
	${RM} -f ${WRKSRC}/hdf/zlib/Makefile
	${ECHO} #Phony makefile > ${WRKSRC}/hdf/zlib/Makefile
	${ECHO} >> ${WRKSRC}/hdf/zlib/Makefile
	${ECHO} libzlib.a: >> ${WRKSRC}/hdf/zlib/Makefile
	printf '\t@echo Using the already installed ZLIB library\n' \
		>> ${WRKSRC}/hdf/zlib/Makefile
	printf '\nclean:\n\ttrue\n' >> ${WRKSRC}/hdf/zlib/Makefile
	printf '\ninstall-lib:\n\ttrue\n' >> ${WRKSRC}/hdf/zlib/Makefile
	printf '\ninstall:\n\ttrue\n' >> ${WRKSRC}/hdf/zlib/Makefile
	-ln -s /usr/lib/${BINFORMAT}/libz* ${WRKSRC}/hdf/zlib/
	-ln -s /usr/include/zconf.h /usr/include/zlib.h ${WRKSRC}/hdf/zlib/

post-install:
.if !defined(NOMANCOMPRESS)
	@for man_page in `grep man./ ${PKGDIR}/PLIST` ; do \
		mp=`echo $${man_page} | ${SED} s/\.gz//` ;\
		${ECHO} Compressing ${PREFIX}/$$mp ;\
		${GZIP_CMD} ${PREFIX}/$$mp ; done
.endif
	@for binary in `grep ^bin/ ${PKGDIR}/PLIST` ; do strip ${PREFIX}/$$binary; done
	${LDCONFIG} -m ${PREFIX}/lib

test:
	cd ${WRKSRC}; make ${MAKE_FLAGS} ${MAKEFILE} test

.include <bsd.port.mk>
