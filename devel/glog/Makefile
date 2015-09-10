# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	glog
PORTVERSION=	0.3.4
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library of C++ classes for flexible logging

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libgflags.so:${PORTSDIR}/devel/gflags

OPTIONS_DEFINE=	DOCS

CPPFLAGS+=	-I${LOCALBASE}/include
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
LDFLAGS+=	-L${LOCALBASE}/lib -lexecinfo
USE_LDCONFIG=	yes
USES=		execinfo libtool pathfix

PORTDOCS=	*

GH_ACCOUNT=	google
USE_GITHUB=	yes

post-patch:
	@${REINPLACE_CMD} -e '/^docdir = / s| = .*| = ${DOCSDIR}|' ${WRKSRC}/Makefile.in

regression-test test: build
	cd ${WRKSRC}/ && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} check

.include <bsd.port.mk>
