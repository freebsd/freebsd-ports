PORTNAME=	samurai
DISTVERSION=	1.2-2024.09.04
DISTVERSIONSUFFIX=	-${GH_TAGNAME}
CATEGORIES=	devel

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Ninja-compatible build tool written in C
WWW=		https://github.com/michaelforney/samurai

LICENSE=	APACHE20 MIT
LICENSE_COMB=	multi
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE

USES=		cpe
CPE_VENDOR=	${PORTNAME}_project

USE_GITHUB=	yes
GH_ACCOUNT=	michaelforney
GH_TAGNAME=	1890235

ALL_TARGET=	samu
PLIST_FILES=	bin/samu \
		share/man/man1/samu.1.gz

.include <bsd.port.mk>
