# Created by: Alexandr Kovalenko <never@nevermind.kiev.ua>
# $FreeBSD$

PORTNAME=	enca
PORTVERSION=	1.13
CATEGORIES=	converters textproc russian ukrainian
MASTER_SITES=	http://dl.cihar.com/enca/

MAINTAINER=	never@nevermind.kiev.ua
COMMENT=	A package for detecting encoding of text files

BUILD_DEPENDS=	umap:${PORTSDIR}/converters/p5-Unicode-Map8
LIB_DEPENDS=	recode:${PORTSDIR}/converters/recode
RUN_DEPENDS=	umap:${PORTSDIR}/converters/p5-Unicode-Map8

LICENSE=	GPLv2

USE_AUTOTOOLS=	libtool
USES=		pkgconfig iconv
USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-html-dir=${DOCSDIR}

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=	enca.1
MLINKS=	enca.1 enconv.1

NO_STAGE=	yes
post-patch::
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's#\ devel-docs##g' ${WRKSRC}/Makefile.in
.endif
	@${REINPLACE_CMD} -e 's/$$(LN_S)/$$(LN_S) -f/' ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
