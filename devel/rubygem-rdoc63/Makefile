PORTNAME=	rdoc
PORTVERSION=	6.3.3
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	63

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	RDoc produces HTML and command-line documentation for Ruby projects

LICENSE=	GPLv2 RUBY
LICENSE_COMB=	dual
LICENSE_FILE_RUBY=	${WRKSRC}/LICENSE.rdoc

USES=		cpe gem
USE_RUBY=	yes

NO_ARCH=	yes

CPE_VENDOR=	ruby-lang

PORTSCOUT=	limit:^6\.3\.

.include <bsd.port.pre.mk>

post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/rdoc
	${RM} ${STAGEDIR}${PREFIX}/bin/ri
	${RM} ${STAGEDIR}${PREFIX}/share/man/man1/ri.1 

.include <bsd.port.post.mk>
