# Created by: skreuzer@FreeBSD.org
# $FreeBSD$

PORTNAME=	zookeeper
PORTVERSION=	3.5.5
CATEGORIES=	devel
MASTER_SITES=	APACHE/${PORTNAME}/current
PKGNAMEPREFIX=	lib
DISTNAME=	apache-${PORTNAME}-${PORTVERSION}

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	C client interface to Zookeeper server

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcppunit.so:devel/cppunit

USES=		autoreconf libtool pkgconfig

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}/zookeeper-client/zookeeper-client-c

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/* ${STAGEDIR}${PREFIX}/lib/*.so
	${LN} -sf libzookeeper_mt.so.2 ${STAGEDIR}${PREFIX}/lib/libzookeeper_mt.so
	${LN} -sf libzookeeper_st.so.2 ${STAGEDIR}${PREFIX}/lib/libzookeeper_st.so

.include <bsd.port.mk>
