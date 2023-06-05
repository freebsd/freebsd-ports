PORTNAME=	libfortuna
PORTVERSION=	0.1.1
CATEGORIES=	devel

MAINTAINER=	waitman@waitman.net
COMMENT=	Fortuna PRNG Library
WWW=		http://crxwg.com/fortuna/bin/libfortuna.html

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_ACCOUNT=	waitman
GH_TAGNAME=	11cbd88

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=array-parameter
.endif

.include <bsd.port.post.mk>
