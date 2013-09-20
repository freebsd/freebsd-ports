# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ucl
PORTVERSION=	1.03
PORTREVISION=	1
CATEGORIES=	archivers devel
MASTER_SITES=	http://www.oberhumer.com/opensource/ucl/download/

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	Data compression library with low memory usage

LICENSE=	GPLv2

NO_STAGE=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared

PORTDOCS=	AUTHORS NEWS README THANKS TODO

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/examples/.libs/uclpack ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA}	${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
