# Created by: Alexandr Kovalenko <never@nevermind.kiev.ua>
# $FreeBSD$

PORTNAME=	enca
PORTVERSION=	1.13
CATEGORIES=	converters textproc russian ukrainian
MASTER_SITES=	http://dl.cihar.com/enca/

MAINTAINER=	never@nevermind.kiev.ua
COMMENT=	Detect encoding of text files

BUILD_DEPENDS=	umap:${PORTSDIR}/converters/p5-Unicode-Map8
LIB_DEPENDS=	librecode.so:${PORTSDIR}/converters/recode
RUN_DEPENDS=	umap:${PORTSDIR}/converters/p5-Unicode-Map8

LICENSE=	GPLv2

USE_AUTOTOOLS=	libtool
USES=		gmake pkgconfig iconv tar:bzip2
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-html-dir=${DOCSDIR}

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch::
	@${REINPLACE_CMD} -e 's/$$(LN_S)/$$(LN_S) -f/' ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
