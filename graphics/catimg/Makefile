PORTNAME=	catimg
DISTVERSIONPREFIX=	v
DISTVERSION=	2.8.0
CATEGORIES=	graphics

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Insanely fast image printing in your terminal
WWW=		https://github.com/posva/catimg/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake cpe
USE_GITHUB=	yes
GH_ACCOUNT=	posva

CPE_VENDOR=	catimg_project

PLIST_FILES=	bin/catimg \
		share/man/man1/catimg.1.gz

.include <bsd.port.mk>
