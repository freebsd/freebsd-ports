# Created by: Vlad GALU <dudu@dudu.ro>
# $FreeBSD$

PORTNAME=	mysql++
PORTVERSION=	3.1.0
PORTREVISION=	1
CATEGORIES=	databases devel
MASTER_SITES=	http://tangentsoft.net/mysql++/releases/ \
		T32.TecNik93.com/ports/others_ports/${PORTNAME}/sources/
PKGNAMESUFFIX=	-mysql${MYSQL_VER}

MAINTAINER=	dudu@dudu.ro
COMMENT=	Complex C++ API for MySQL${MYSQL_VER}

USES=		gmake
USE_MYSQL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-mysql=${LOCALBASE} --enable-thread-check
USE_LDCONFIG=	yes
PLIST_SUB+=	VER=${PORTVERSION}

CONFLICTS=	${PORTNAME}*-1.*

PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc/ && ${COPYTREE_SHARE} pdf ${STAGEDIR}${DOCSDIR})
	(cd ${WRKSRC}/doc/ && ${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR})
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.h ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.cpp ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
