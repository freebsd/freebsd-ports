PORTNAME=	libtar
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.20
CATEGORIES=	devel

MAINTAINER=	manuelj.munoz@gmail.com
COMMENT=	Library for manipulating POSIX and GNU tar files
WWW=		https://repo.or.cz/w/libtar.git

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USES=		autoreconf cpe gmake libtool
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	tklauser

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared

CPE_VENDOR=	feep

CPPFLAGS+=	-fPIC

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libtar.so.0.0.0

.include <bsd.port.mk>
