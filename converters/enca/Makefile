# Created by: Alexandr Kovalenko <never@nevermind.kiev.ua>
# $FreeBSD$

PORTNAME=	enca
PORTVERSION=	1.19
CATEGORIES=	converters textproc russian ukrainian
MASTER_SITES=	http://dl.cihar.com/enca/

MAINTAINER=	never@nevermind.kiev.ua
COMMENT=	Detect encoding of text files

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	umap:converters/p5-Unicode-Map8
LIB_DEPENDS=	librecode.so:converters/recode
RUN_DEPENDS=	umap:converters/p5-Unicode-Map8

USES=		gmake iconv libtool localbase pathfix pkgconfig tar:xz
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-html-dir=${DOCSDIR}
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} '/SUBDIRS =/s/test//' ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
