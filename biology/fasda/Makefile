PORTNAME=	fasda
DISTVERSION=	0.2.0-1
DISTVERSIONSUFFIX=	-ga7d14ad
CATEGORIES=	biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Fast and simple differential analysis
WWW=		https://github.com/auerlab/fasda

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libxtend.so:devel/libxtend libbiolibc.so:biology/biolibc
RUN_DEPENDS=	stringtie>0:biology/stringtie

USES=		localbase
USE_GITHUB=	yes

GH_ACCOUNT=	auerlab

MAKE_ARGS=	MANPREFIX=${PREFIX}/share VERSION=${PORTVERSION}
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
