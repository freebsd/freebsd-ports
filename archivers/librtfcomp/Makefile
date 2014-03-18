# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	librtfcomp
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	SF/synce/SynCE/${PORTNAME}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT?=	Library for handling compressed RTF documents

LICENSE=	LGPL21

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		libtool

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

post-install:
.if !defined(SLAVEPORT)
	${INSTALL_SCRIPT} ${WRKSRC}/tests/fromrtf ${STAGEDIR}${PREFIX}/bin/fromrtf
	${INSTALL_SCRIPT} ${WRKSRC}/tests/test ${STAGEDIR}${PREFIX}/bin/testrtf
	${INSTALL_SCRIPT} ${WRKSRC}/tests/tortf ${STAGEDIR}${PREFIX}/bin/tortf
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/librtfcomp.so.0.0.0
.endif
.if defined(SLAVEPORT) && ${SLAVEPORT} == "py"
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/pyrtfcomp.so
.endif

.include <bsd.port.mk>
