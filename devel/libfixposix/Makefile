# $FreeBSD$

PORTNAME=	libfixposix
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.3
CATEGORIES=	devel

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Replacement for inconsistent parts of POSIX

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENCE

USES=		autoreconf libtool pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	sionescu
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
