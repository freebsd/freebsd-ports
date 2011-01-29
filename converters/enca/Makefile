# Ports collection makefile for:  enca
# Date created:			  Fri Sep 20, 2002
# Whom:				  Alexandr Kovalenko <never@nevermind.kiev.ua>
#
# $FreeBSD$
#

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
USE_GNOME=	pkgconfig
USE_ICONV=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes
CONFIGURE_ARGS=	--with-html-dir=${DOCSDIR}

CONFIGURE_ENV=	CPPFLAGS=-I${LOCALBASE}/include \
		LDFLAGS=-L${LOCALBASE}/lib

MAN1=	enca.1
MLINKS=	enca.1 enconv.1

post-patch::
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's#\ devel-docs##g' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
