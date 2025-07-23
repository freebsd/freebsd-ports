PORTNAME=	enca
PORTVERSION=	1.19
PORTREVISION=	1
CATEGORIES=	converters textproc russian ukrainian
MASTER_SITES=	http://dl.cihar.com/enca/

MAINTAINER=	never@nevermind.kiev.ua
COMMENT=	Detect encoding of text files
WWW=		http://gitorious.org/enca

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	umap:converters/p5-Unicode-Map8
LIB_DEPENDS=	librecode.so:converters/recode
RUN_DEPENDS=	umap:converters/p5-Unicode-Map8

USES=		gmake iconv libtool localbase pkgconfig tar:xz
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--with-html-dir=${DOCSDIR}
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} '/SUBDIRS =/s/test//' ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
