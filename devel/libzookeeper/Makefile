# Created by: skreuzer@FreeBSD.org
# $FreeBSD$

PORTNAME=	zookeeper
PORTVERSION=	3.4.9
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	APACHE/${PORTNAME}/current
PKGNAMEPREFIX=	lib

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	C client interface to Zookeeper server

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcppunit.so:devel/cppunit

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	uses x86 assembly

USES=		gmake libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}/src/c

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/* ${STAGEDIR}${PREFIX}/lib/*.so
	${LN} -sf libzookeeper_mt.so.2 ${STAGEDIR}${PREFIX}/lib/libzookeeper_mt.so
	${LN} -sf libzookeeper_st.so.2 ${STAGEDIR}${PREFIX}/lib/libzookeeper_st.so

.include <bsd.port.mk>
