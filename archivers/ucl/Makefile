# Created by: Maxim Sobolev <sobomax@FreeBSD.org>

PORTNAME=	ucl
PORTVERSION=	1.03
PORTREVISION=	5
CATEGORIES=	archivers devel
MASTER_SITES=	http://www.oberhumer.com/opensource/ucl/download/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Data compression library with low memory usage

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool

CONFIGURE_ARGS=	--enable-shared
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

PORTDOCS=	AUTHORS NEWS README THANKS TODO

CONFLICTS_INSTALL=	libucl

OPTIONS_DEFINE=	DOCS

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/examples/.libs/uclpack ${STAGEDIR}${PREFIX}/bin

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA}	${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
