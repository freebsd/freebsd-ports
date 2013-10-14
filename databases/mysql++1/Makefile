# Created by: Miklos Niedermayer <mico@bsd.hu>
# $FreeBSD$

PORTNAME=	mysql++
PORTVERSION=	1.7.40
PORTREVISION=	2
CATEGORIES=	databases devel
MASTER_SITES=	http://tangentsoft.net/mysql++/releases/
PKGNAMESUFFIX=	1-mysql${MYSQL_VER}

MAINTAINER=	sergey@network-asp.biz
COMMENT=	Complex C++ API for MySQL${MYSQL_VER}

USE_MYSQL=	yes
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--with-mysql=${LOCALBASE} \
		--includedir=${PREFIX}/include/mysql++ \
		--disable-examples
USE_LDCONFIG=	yes

CONFLICTS=	${PORTNAME}*-2.*

NO_STAGE=	yes
post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/userman/html ${DOCSDIR}/refman/html
	@${INSTALL_DATA} ${WRKSRC}/doc/userman/html/* ${DOCSDIR}/userman/html
	@${INSTALL_DATA} ${WRKSRC}/doc/refman/html/* ${DOCSDIR}/refman/html
	@${INSTALL_DATA} ${WRKSRC}/doc/*.pdf ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/examples/*.cpp ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/examples/*.h ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/examples/README ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/examples/Makefile.simple ${EXAMPLESDIR}/Makefile.temp
	@${SED} -e "s|/usr/include/mysql++|${PREFIX}/include/mysql++|" < ${EXAMPLESDIR}/Makefile.temp | \
		${SED} -e "s|/usr/include/mysql|${LOCALBASE}/include/mysql|" | \
		${SED} -e "s|-lmysqlpp|-L${PREFIX}/lib -L${LOCALBASE}/lib/mysql -lmysqlpp|" \
		> ${EXAMPLESDIR}/Makefile
	@${RM} -f ${EXAMPLESDIR}/Makefile.temp
.endif

.include <bsd.port.mk>
