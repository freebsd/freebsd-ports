# ports collection makefile for:	MySQL++
# Date created:				20th July 2000
# Whom:					Miklos Niedermayer <mico@bsd.hu>
#
# $FreeBSD$
#

PORTNAME=	mysql++
PORTVERSION=	1.7
CATEGORIES=	databases devel
MASTER_SITES=	http://gd.tuwien.ac.at/db/mysql/mysql++/ \
		http://www.mysql.com/Downloads/mysql++/

MAINTAINER=	mico@bsd.hu

LIB_DEPENDS=	mysqlclient:${PORTSDIR}/databases/mysql322-client

HAS_CONFIGURE=	yes
CONFIGURE_ENV=	CXXFLAGS="${CXXFLAGS} -D_FIX_FOR_BSD_ "
INSTALLS_SHLIB=	yes

pre-configure:
	${RM} ${WRKSRC}/examples/Makefile.in
	${ECHO} "all:" >${WRKSRC}/examples/Makefile.in
	${ECHO} "install:" >>${WRKSRC}/examples/Makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sqlplusint/.libs/libsqlplus.so.1 ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/sqlplusint/.libs/libsqlplus.a ${PREFIX}/lib
	(cd ${PREFIX}/lib && ${RM} -f libsqlplus.so && ${LN} -s libsqlplus.so.1 libsqlplus.so)
	ranlib ${PREFIX}/lib/libsqlplus.a
	${MKDIR} ${PREFIX}/share/examples/mysql++
	${MKDIR} ${PREFIX}/share/doc/mysql++
	${INSTALL_DATA} ${WRKSRC}/examples/*.cc ${PREFIX}/share/examples/mysql++
	${INSTALL_DATA} ${WRKSRC}/doc/man-text/* ${PREFIX}/share/doc/mysql++
	${MKDIR} ${PREFIX}/include/mysql
	${INSTALL_DATA} ${WRKSRC}/sqlplusint/mysql++ ${WRKSRC}/sqlplusint/*.hh ${PREFIX}/include/mysql
	${INSTALL_DATA} ${FILESDIR}/README ${PREFIX}/share/examples

.include <bsd.port.mk>
