# Created by: Vlad GALU <dudu@dudu.ro>
# $FreeBSD$

PORTNAME=	mysql++
PORTVERSION=	3.2.2
CATEGORIES=	databases devel
MASTER_SITES=	http://tangentsoft.net/mysql++/releases/ \
		T32.TecNik93.com/ports/others_ports/${PORTNAME}/sources/
PKGNAMESUFFIX=	-mysql${MYSQL_VER}

MAINTAINER=	dudu@dudu.ro
COMMENT=	Complex C++ API for MySQL${MYSQL_VER}

USES=		gmake mysql
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-mysql=${LOCALBASE} --enable-thread-check
USE_LDCONFIG=	yes
PLIST_SUB+=	VER=${PORTVERSION}

CONFLICTS=	${PORTNAME}*-1.*

PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
# Avoid conflict with C++20 <version> by ignoring <...> under WRKSRC
	@${REINPLACE_CMD} -i .c++20 '/MYSQLPP_CXXFLAGS/s/-I/-iquote/' \
		${WRKSRC}/Makefile.in

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc/ && ${COPYTREE_SHARE} pdf ${STAGEDIR}${DOCSDIR})
	(cd ${WRKSRC}/doc/ && ${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR})

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.h ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.cpp ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
