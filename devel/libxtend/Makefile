PORTNAME=	libxtend
DISTVERSION=	0.1.8-2
DISTVERSIONSUFFIX=	-ge883e5e
CATEGORIES=	devel

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Miscellaneous functions to extend libc
WWW=		https://github.com/outpaddling/libxtendc

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
USE_LDCONFIG=	yes

GH_ACCOUNT=	outpaddling

INSTALL_TARGET=	install-strip

pre-build:
	cd ${WRKSRC} && ${MAKE} depend

.include <bsd.port.mk>
