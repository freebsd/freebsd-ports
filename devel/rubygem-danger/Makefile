PORTNAME=	danger
PORTVERSION=	9.5.3
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Code Review
WWW=		https://github.com/danger/danger

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-base64>=0.2<1:converters/rubygem-base64 \
		rubygem-claide>=1.0<2:devel/rubygem-claide \
		rubygem-claide-plugins>=0.9.2:devel/rubygem-claide-plugins \
		rubygem-colored2>=3.1<5:textproc/rubygem-colored2 \
		rubygem-cork>=0.1<1:devel/rubygem-cork \
		rubygem-faraday-gitlab>=0.9.0<3.0:www/rubygem-faraday-gitlab \
		rubygem-faraday-http-cache-gitlab>=2.0.0<3:www/rubygem-faraday-http-cache-gitlab \
		rubygem-git>=1.13<3:devel/rubygem-git \
		rubygem-kramdown-gitlab>=2.5.1<3:textproc/rubygem-kramdown-gitlab \
		rubygem-kramdown-parser-gfm-gitlab>=1.0<2:textproc/rubygem-kramdown-parser-gfm-gitlab \
		rubygem-octokit-gitlab>=4:net/rubygem-octokit-gitlab \
		rubygem-pstore>=0.1<1:devel/rubygem-pstore \
		rubygem-terminal-table>=1<5:textproc/rubygem-terminal-table

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/danger

.include <bsd.port.mk>
