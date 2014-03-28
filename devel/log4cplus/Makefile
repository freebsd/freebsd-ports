# Created by: Petri Totterman <petri.totterman@hmv.fi>
# $FreeBSD$

PORTNAME=	log4cplus
PORTVERSION=	1.1.2
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-stable/${PORTVERSION}

MAINTAINER=	reed@reedmedia.net
COMMENT=	Logging library for C++

OPTIONS_DEFINE=	DOCS

USES=		libtool pathfix
USE_XZ=		yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-threads=yes
MAKE_JOBS_UNSAFE=	yes

PORTDOCS=	*

post-install:
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${STAGEDIR}${PREFIX}/include/log4cplus
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/docs/*.config ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/docs/*.html ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/docs/doxygen.css ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
