# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	librtfcomp
PORTVERSION=	1.3
CATEGORIES=	archivers
MASTER_SITES=	SF/synce/SynCE/${PORTNAME}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT?=	Library for handling compressed RTF documents

LICENSE=	LGPL21

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes

SLAVEDIRS=	archivers/py-librtfcomp

.if defined(SLAVEPORT) && ${SLAVEPORT} == "py"
CATEGORIES+=	python
CONFIGURE_ARGS+=--enable-python-bindings
.else
CONFIGURE_ARGS+=--disable-python-bindings
.endif

post-patch:
	@${REINPLACE_CMD} -e '/VISIBILITY=/ s| -fvisibility=hidden||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|$$(top_builddir)/src/librtfcomp.la|${LOCALBASE}/lib/librtfcomp.la|g' ${WRKSRC}/python/Makefile.in

post-build:
.if !defined(SLAVEPORT)
	@${STRIP_CMD} ${WRKSRC}/src/.libs/librtfcomp.so.0
.endif

post-install:
.if !defined(SLAVEPORT)
	${INSTALL_SCRIPT} ${WRKSRC}/tests/fromrtf ${STAGEDIR}${PREFIX}/bin/fromrtf
	${INSTALL_SCRIPT} ${WRKSRC}/tests/test ${STAGEDIR}${PREFIX}/bin/testrtf
	${INSTALL_SCRIPT} ${WRKSRC}/tests/tortf ${STAGEDIR}${PREFIX}/bin/tortf
.endif

.include <bsd.port.mk>
