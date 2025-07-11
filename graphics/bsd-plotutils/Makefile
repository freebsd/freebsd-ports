PORTNAME=	bsd-plotutils
DISTVERSION=	1.4.2
PORTREVISION=	4
CATEGORIES=	graphics

MAINTAINER=	toranktto@gmail.com
COMMENT=	Traditional plotting utilities
WWW=		https://github.com/Toranktto/bsd-plotutils

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	Toranktto
USE_LDCONFIG=	yes

CONFLICTS_INSTALL=	plotutils

MAKE_ARGS=	MANDIR="${PREFIX}/share/man/man"

OPTIONS_DEFINE=	FORTRAN
OPTIONS_SUB=	yes

FORTRAN_DESC=	FORTRAN 77 support

FORTRAN_USES=	fortran

.include <bsd.port.pre.mk>

.if defined(NO_PROFILE) || ${OPSYS} == FreeBSD
PLIST_SUB+=	PROFILE="@comment "
.else
PLIST_SUB+=	PROFILE=""
.endif

post-patch:
	@${REINPLACE_CMD} -e "s/py27plot//g" ${WRKSRC}/libplot/bindings/Makefile
	@${REINPLACE_CMD} -e '/#pragma GCC diagnostic/d' ${WRKSRC}/graph/graph.c

post-patch-FORTRAN-on:
	@${REINPLACE_CMD} -e "s/f77plot//g" ${WRKSRC}/libplot/bindings/Makefile

.include <bsd.port.post.mk>
