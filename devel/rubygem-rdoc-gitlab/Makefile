PORTNAME=	rdoc
PORTVERSION=	6.3.4.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	RDoc produces HTML and command-line documentation for Ruby projects
WWW=		https://ruby.github.io/rdoc/ \
		https://github.com/ruby/rdoc

LICENSE=	GPLv2 RUBY
LICENSE_COMB=	dual
LICENSE_FILE_RUBY=	${WRKSRC}/LICENSE.rdoc

USES=		cpe gem

NO_ARCH=	yes

PLIST_FILES=	bin/rdoc \
		bin/ri \
		share/man/man1/ri.1.gz

CPE_VENDOR=	ruby-lang

post-install:
	${INSTALL_DATA} ${WRKSRC}/man/ri.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
