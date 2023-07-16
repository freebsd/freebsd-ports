PORTNAME=	libs11n
PORTVERSION=	1.2.10
DISTVERSIONSUFFIX=	-nobuildfiles
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF/s11n/s11n/${PORTVERSION}/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	C++ library for easily serializing a wide variety of objects
WWW=		http://s11n.net/

LICENSE=	PD

USES=		uidfix zip
USE_CXXSTD=	c++11
USE_LDCONFIG=	yes

PORTSCOUT=	limitw:1,even

WRKSRC_SUBDIR=	src

.include <bsd.port.pre.mk>

.if defined(NO_PROFILE) || ( ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 )))
PLIST_SUB+=	PROFILE="@comment "
.else
PLIST_SUB+=	PROFILE=""
.endif

post-extract:
	@${CP} ${PATCHDIR}/Makefile.bsd ${WRKSRC}/Makefile

post-patch:
.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1400091
	@${REINPLACE_CMD} -e 's|auto_ptr|unique_ptr|' \
		${WRKSRC}/../include/s11n.net/s11n/algo.tpp \
		${WRKSRC}/../include/s11n.net/s11n/io/data_node_format.hpp \
		${WRKSRC}/../include/s11n.net/s11n/io/data_node_io.hpp
.endif

pre-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/s11n.net
	${MKDIR} ${STAGEDIR}${PREFIX}/include/s11n.net/s11n
	${MKDIR} ${STAGEDIR}${PREFIX}/include/s11n.net/s11n/io
	${MKDIR} ${STAGEDIR}${PREFIX}/include/s11n.net/s11n/nodeutil
	${MKDIR} ${STAGEDIR}${PREFIX}/include/s11n.net/s11n/plugin
	${MKDIR} ${STAGEDIR}${PREFIX}/include/s11n.net/s11n/proxy
	${MKDIR} ${STAGEDIR}${PREFIX}/include/s11n.net/s11n/proxy/pod
	${MKDIR} ${STAGEDIR}${PREFIX}/include/s11n.net/s11n/proxy/std

.include <bsd.port.post.mk>
