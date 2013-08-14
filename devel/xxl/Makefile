# Created by: Robert Schlotterbeck <robert@rs.tarrant.tx.us>
# $FreeBSD$

PORTNAME=	xxl
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://launchpadlibrarian.net/39195019/ \
		http://www.zork.org/software/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C/C++ library for exception handling and asset management

LICENSE=	BSD

OPTIONS_DEFINE=	THREADS DOCS
OPTIONS_DEFAULT=THREADS

USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes

PORTDOCS=	xxl.html xxl.pdf

.include <bsd.port.options.mk>

.if !${PORT_OPTIONS:MTHREADS}
CONFIGURE_ARGS+=--without-threads
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR})
.endif

regression-test test: build
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} \
		${MAKEFILE} ${MAKE_ARGS} check)

.include <bsd.port.mk>
