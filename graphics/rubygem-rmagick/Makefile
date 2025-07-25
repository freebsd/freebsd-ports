PORTNAME=	rmagick
PORTVERSION=	6.1.2
CATEGORIES=	graphics rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby binding for ImageMagick
WWW=		https://rmagick.github.io/ \
		https://github.com/rmagick/rmagick

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-observer>=0.1<1:devel/rubygem-observer \
		rubygem-pkg-config>=1.4<2:devel/rubygem-pkg-config

USES=		gem pkgconfig shebangfix

SHEBANG_FILES=	.devcontainer/*.sh

OPTIONS_DEFINE=	X11
OPTIONS_DEFAULT=X11

X11_USES=		magick:7
X11_USES_OFF=		magick:7,nox11

.include <bsd.port.mk>
