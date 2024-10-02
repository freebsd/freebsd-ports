PORTNAME=	minitar-cli
PORTVERSION=	0.12
CATEGORIES=	archivers rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	0

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library and command-line utility for tar archives
WWW=		https://github.com/halostatue/minitar-cli

LICENSE=	BSD2CLAUSE RUBY
LICENSE_COMB=	dual
LICENSE_FILE_BSD2CLAUSE=${WRKSRC}/docs/bsdl.txt
LICENSE_FILE_RUBY=	${WRKSRC}/docs/ruby.txt

RUN_DEPENDS=	rubygem-minitar0>=${PORTVERSION}.0<0.13:archivers/rubygem-minitar0 \
		rubygem-powerbar>=1.0<2:devel/rubygem-powerbar

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^0\.

post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/minitar

.include <bsd.port.mk>
