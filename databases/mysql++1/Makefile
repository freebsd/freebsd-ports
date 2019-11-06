# Created by: Miklos Niedermayer <mico@bsd.hu>
# $FreeBSD$

PORTNAME=	mysql++
PORTVERSION=	1.7.40
PORTREVISION=	3
CATEGORIES=	databases devel
MASTER_SITES=	http://tangentsoft.net/mysql++/releases/
PKGNAMESUFFIX=	1-mysql${MYSQL_VER}

MAINTAINER=	sergey@network-asp.biz
COMMENT=	Complex C++ API for MySQL${MYSQL_VER}

BROKEN=		unfetchable

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LGPL

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-mysql=${LOCALBASE} \
		--includedir=${PREFIX}/include/mysql++ \
		--disable-examples
INSTALL_TARGET=	install-strip
USES=		libtool mysql
USE_LDCONFIG=	yes

CONFLICTS=	${PORTNAME}*-2.*

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/userman/html ${STAGEDIR}${DOCSDIR}/refman/html
	${INSTALL_DATA} ${WRKSRC}/doc/userman/html/* ${STAGEDIR}${DOCSDIR}/userman/html
	${INSTALL_DATA} ${WRKSRC}/doc/refman/html/* ${STAGEDIR}${DOCSDIR}/refman/html
	${INSTALL_DATA} ${WRKSRC}/doc/*.pdf ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.cpp ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.h ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/README ${STAGEDIR}${EXAMPLESDIR}
	${SED} -e "s|/usr/include/mysql++|${PREFIX}/include/mysql++|" < ${WRKSRC}/examples/Makefile.simple | \
		${SED} -e "s|/usr/include/mysql|${LOCALBASE}/include/mysql|" | \
		${SED} -e "s|-lmysqlpp|-L${PREFIX}/lib -L${LOCALBASE}/lib/mysql -lmysqlpp|" \
		> ${STAGEDIR}${EXAMPLESDIR}/Makefile

.include <bsd.port.mk>
