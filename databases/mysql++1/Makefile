# ports collection makefile for:	MySQL++
# Date created:				20th July 2000
# Whom:					Miklos Niedermayer <mico@bsd.hu>
#
# $FreeBSD$
#

PORTNAME=	mysql++
PORTVERSION=	1.7.20
CATEGORIES=	databases devel
MASTER_SITES=	http://tangentsoft.net/mysql++/releases/

MAINTAINER=	mico@bsd.hu
COMMENT=	Complex C++ API for MySQL

USE_MYSQL=	yes
USE_GMAKE=	yes
USE_PERL5=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-mysql=${LOCALBASE} \
		--with-mysql-include=${LOCALBASE}/include/mysql/ \
		--with-mysql-lib=${LOCALBASE}/lib/mysql/
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500039
USE_GCC=	3.3
.endif

.if ${OSVERSION} >= 502126
USE_GCC=	3.3
.endif

pre-configure:
	@${RM} ${WRKSRC}/examples/Makefile.in
	@${ECHO} "all:" >${WRKSRC}/examples/Makefile.in
	@${ECHO} "install:" >>${WRKSRC}/examples/Makefile.in

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/sqlplusint/.libs/libmysqlpp.so.2 ${PREFIX}/lib
	@${INSTALL_DATA} ${WRKSRC}/sqlplusint/.libs/libmysqlpp.a ${PREFIX}/lib
	@(cd ${PREFIX}/lib && ${RM} -f libmysqlpp.so && ${LN} -s libmysqlpp.so.2 libmysqlpp.so)
	@ranlib ${PREFIX}/lib/libmysqlpp.a
	@${MKDIR} ${PREFIX}/include/mysql++
	@(cd ${WRKSRC}/sqlplusint/; \
		${INSTALL_DATA} *.hh ${PREFIX}/include/mysql++; \
		${INSTALL_DATA} *.h ${PREFIX}/include/mysql++)
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/man-text/*.txt ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
