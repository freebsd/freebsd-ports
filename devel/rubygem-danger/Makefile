PORTNAME=	danger
PORTVERSION=	8.6.1
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Code Review

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-claide>=1.0<2:devel/rubygem-claide \
		rubygem-claide-plugins>=0.9.2:devel/rubygem-claide-plugins \
		rubygem-colored2>=3.1<4:textproc/rubygem-colored2 \
		rubygem-cork>=0.1<1:devel/rubygem-cork \
		rubygem-faraday1>=0.9.0<2.0:www/rubygem-faraday1 \
		rubygem-faraday-http-cache>=2.0.0<3:www/rubygem-faraday-http-cache \
		rubygem-git>=1.7<2:devel/rubygem-git \
		rubygem-kramdown>=2.3<3:textproc/rubygem-kramdown \
		rubygem-kramdown-parser-gfm>=1.0<2:textproc/rubygem-kramdown-parser-gfm \
		rubygem-no_proxy_fix>=0:net/rubygem-no_proxy_fix \
		rubygem-octokit>=4.7<5:net/rubygem-octokit \
		rubygem-terminal-table>=1<4:textproc/rubygem-terminal-table

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/danger

.include <bsd.port.mk>
