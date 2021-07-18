PORTNAME=	gitlab-rdoc
PORTVERSION=	6.3.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	RDoc produces HTML and command-line documentation for Ruby projects

LICENSE=	GPLv2 RUBY
LICENSE_COMB=	dual
LICENSE_FILE_RUBY=	${WRKSRC}/LICENSE.rdoc

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/rdoc
	${RM} ${STAGEDIR}${PREFIX}/bin/ri

.include <bsd.port.mk>
