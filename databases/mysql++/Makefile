# ports collection makefile for:	MySQL++
# Date created:				20th July 2000
# Whom:					Miklos Niedermayer <mico@bsd.hu>
#
# $FreeBSD$
#

PORTNAME=	mysql++
PORTVERSION=	1.7.27
CATEGORIES=	databases devel
MASTER_SITES=	http://tangentsoft.net/mysql++/releases/

MAINTAINER=	sergey@network-asp.biz
COMMENT=	Complex C++ API for MySQL

USE_MYSQL=	yes
USE_GMAKE=	yes
USE_PERL5=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-mysql=${LOCALBASE}
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500039
USE_GCC=	3.3
.endif

PKGNAMESUFFIX=	-mysql${MYSQL_VER}
COMMENT+=	${MYSQL_VER}

pre-configure:
	@${RM} ${WRKSRC}/examples/Makefile.in
	@${ECHO} "all:" >${WRKSRC}/examples/Makefile.in
	@${ECHO} "install:" >>${WRKSRC}/examples/Makefile.in

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/lib/.libs/libmysqlpp.so.4 ${PREFIX}/lib
	@${INSTALL_DATA} ${WRKSRC}/lib/.libs/libmysqlpp.a ${PREFIX}/lib
	@(cd ${PREFIX}/lib && ${RM} -f libmysqlpp.so && ${LN} -s libmysqlpp.so.4 libmysqlpp.so)
	@ranlib ${PREFIX}/lib/libmysqlpp.a
	@${MKDIR} ${PREFIX}/include/mysql++
	@(cd ${WRKSRC}/lib/; \
		${INSTALL_DATA} *.hh ${PREFIX}/include/mysql++; \
		${INSTALL_DATA} *.h ${PREFIX}/include/mysql++)
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/man-text/*.txt ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
