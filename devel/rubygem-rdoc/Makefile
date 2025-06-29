PORTNAME=	rdoc
PORTVERSION=	6.14.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	RDoc produces HTML and command-line documentation for Ruby projects
WWW=		https://ruby.github.io/rdoc/ \
		https://github.com/ruby/rdoc

LICENSE=	GPLv2 RUBY
LICENSE_COMB=	dual
LICENSE_FILE_RUBY=	${WRKSRC}/LICENSE.rdoc

RUN_DEPENDS=	rubygem-erb>=0:devel/rubygem-erb \
		rubygem-psych>=4.0.0:textproc/rubygem-psych

USES=		cpe gem

NO_ARCH=	yes

PLIST_FILES=	bin/rdoc \
		bin/ri \
		share/man/man1/ri.1.gz

CPE_VENDOR=	ruby-lang

post-install:
	${INSTALL_DATA} ${WRKSRC}/man/ri.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
