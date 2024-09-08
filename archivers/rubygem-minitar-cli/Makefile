PORTNAME=	minitar-cli
PORTVERSION=	0.12
CATEGORIES=	archivers rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library and command-line utility for tar archives
WWW=		https://github.com/halostatue/minitar-cli

LICENSE=	BSD2CLAUSE RUBY
LICENSE_COMB=	dual
LICENSE_FILE_BSD2CLAUSE=${WRKSRC}/docs/bsdl.txt
LICENSE_FILE_RUBY=	${WRKSRC}/docs/ruby.txt

RUN_DEPENDS=	rubygem-minitar>=0.12.0<0.13:archivers/rubygem-minitar \
		rubygem-powerbar>=1.0<2:devel/rubygem-powerbar

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/minitar

.include <bsd.port.mk>
