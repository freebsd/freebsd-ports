# Created by: Petri Totterman <petri.totterman@hmv.fi>
# $FreeBSD$

PORTNAME=	log4cplus
PORTVERSION=	1.1.2
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-stable/${PORTVERSION}

MAINTAINER=	reed@reedmedia.net
COMMENT=	Logging library for C++

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

OPTIONS_DEFINE=	DOCS

USES=		compiler:c++11-lang libtool pathfix tar:xz
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-threads=yes
INSTALL_TARGET=	install-strip
MAKE_JOBS_UNSAFE=	yes

PORTDOCS=	*

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.config ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.html ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/doxygen.css ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
