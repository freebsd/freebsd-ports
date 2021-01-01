# $FreeBSD$

PORTNAME=	bsd-plotutils
DISTVERSION=	1.4.2
PORTREVISION=	2
CATEGORIES=	graphics

MAINTAINER=	toranktto@gmail.com
COMMENT=	Traditional plotting utilities

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

OPTIONS_DEFINE=	FORTRAN
OPTIONS_SUB=	yes
FORTRAN_DESC=	FORTRAN 77 support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFORTRAN}
USES+=	fortran
.endif

USE_GITHUB=	yes
GH_ACCOUNT=	Toranktto
GH_PROJECT=	bsd-plotutils

CONFLICTS_INSTALL=	plotutils
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e "s/py27plot//g" ${WRKSRC}/libplot/bindings/Makefile
	@${REINPLACE_CMD} -e '/#pragma GCC diagnostic/d' ${WRKSRC}/graph/graph.c

.if !${PORT_OPTIONS:MFORTRAN}
	@${REINPLACE_CMD} -e "s/f77plot//g" ${WRKSRC}/libplot/bindings/Makefile
.endif

.include <bsd.port.mk>
