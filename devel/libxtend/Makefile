PORTNAME=	libxtend
DISTVERSION=	0.2.0-2
PORTREVISION=	1
DISTVERSIONSUFFIX=	-g5f45f63
CATEGORIES=	devel

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Miscellaneous functions to extend libc
WWW=		https://github.com/outpaddling/libxtendc

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
USE_LDCONFIG=	yes

GH_ACCOUNT=	outpaddling

MAKE_ARGS=	MANDIR=${PREFIX}/share/man
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
