# New ports collection makefile for:	pcre
# Version required:			2.08
# Date created:				08 July 1998
# Whom:					dom
#
# $FreeBSD$
#

DISTNAME=       pcre-2.08
CATEGORIES=     devel
MASTER_SITES=   ftp://ftp.cus.cam.ac.uk/pub/software/programs/pcre/

MAINTAINER=     dom@myrddin.demon.co.uk

MAN3=		pcre.3 pcreposix.3
MAN1=		pgrep.1

do-configure:
	${SED} -e '/^CC/s/.*/CC=${CC}/' \
	       -e '/^CFLAGS/s/.*/CFLAGS=${CFLAGS}/' \
	       -e '/^RANLIB/s/.*/RANLIB=${RANLIB}/' \
	    ${WRKSRC}/Makefile > ${WRKSRC}/Makefile.new
	${MV} ${WRKSRC}/Makefile.new ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pgrep ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/libpcre.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/libpcreposix.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/pcre.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/pcreposix.h ${PREFIX}/include
	${INSTALL_MAN} ${WRKSRC}/pcre.3 ${PREFIX}/man/man3
	${INSTALL_MAN} ${WRKSRC}/pcreposix.3 ${PREFIX}/man/man3
	${INSTALL_MAN} ${WRKSRC}/pgrep.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
