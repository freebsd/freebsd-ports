# Created by: Petri Totterman <petri.totterman@hmv.fi>
# $FreeBSD$

PORTNAME=	log4cplus
PORTVERSION=	1.0.4
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-stable/${PORTVERSION}
DISTFILES=	log4cplus-${PORTVERSION}.tar.bz2

MAINTAINER=	reed@reedmedia.net
COMMENT=	logging library for C++

OPTIONS_DEFINE=	DOCS

USE_GCC=	any
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-threads=yes
MAKE_JOBS_UNSAFE=	yes

PORTDOCS=	*

post-install:
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${STAGEDIR}${PREFIX}/include/log4cplus
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/docs/*.config ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/docs/*.html ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/docs/doxygen.css ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
