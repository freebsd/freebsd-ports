# Created by: skreuzer@FreeBSD.org
# $FreeBSD$

PORTNAME=	zookeeper
PORTVERSION=	3.4.6
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	APACHE/${PORTNAME}/current
PKGNAMEPREFIX=	lib

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	C client interface to Zookeeper server

LICENSE=	APACHE20

LIB_DEPENDS=	libcppunit.so:${PORTSDIR}/devel/cppunit

USES=		gmake libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

WRKSRC=	${WRKDIR}/${DISTNAME}/src/c

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*
	(cd ${STAGEDIR}${PREFIX}/lib; \
		${STRIP_CMD} libzookeeper_mt.so.2; \
		${LN} -nsf ${PREFIX}/lib/libzookeeper_mt.so.2 libzookeeper_mt.so; \
		${STRIP_CMD} libzookeeper_st.so.2; \
		${LN} -nsf ${PREFIX}/lib/libzookeeper_st.so.2 libzookeeper_st.so )

.include <bsd.port.mk>
