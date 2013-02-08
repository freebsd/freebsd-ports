# New ports collection makefile for:	ilmbase
# Date created:				2007-10-07
# Whom:					nork@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	ilmbase
PORTVERSION=	1.0.3
CATEGORIES=	graphics devel
MASTER_SITES=	http://cloud.github.com/downloads/openexr/openexr/

MAINTAINER=	nemysis@gmx.ch
COMMENT=	ILM Base libraries a.k.a. Half, IlmThread, Imath, and Iex

LICENSE=	BSD

CONFLICTS=	OpenEXR-1.[0-4].*

USE_PKGCONFIG=	build
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool

PORTDOCS=	AUTHORS ChangeLog README

OPTIONS_DEFINE=		THREAD
OPTIONS_DEFAULT=	THREAD
THREAD_DESC=		Enable multithreaded file I/O support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTHREAD}
CONFIGURE_ARGS+=--enable-threading
CONFIGURE_ENV+=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"
.else
CONFIGURE_ARGS+=--disable-threading
.endif

regression-test regression test check:	build
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check)

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
