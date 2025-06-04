PORTNAME=	libfortuna
PORTVERSION=	0.1.1
CATEGORIES=	devel

MAINTAINER=	waitman@waitman.net
COMMENT=	Fortuna PRNG Library
WWW=		http://crxwg.com/fortuna/bin/libfortuna.html

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

DEPRECATED=	Legacy fortuna library, last upstream activity 10 years ago
EXPIRATION_DATE=2025-07-31

USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_ACCOUNT=	waitman
GH_TAGNAME=	11cbd88

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=array-parameter
.endif

.include <bsd.port.post.mk>
