PORTNAME=	debug
DISTVERSION=	1.4.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	yasu@FreeBSD.org
COMMENT=	Debugging functionality for Ruby

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-irb>=1.3.6:devel/rubygem-irb \
		rubygem-reline>=0.2.7:devel/rubygem-reline

USES=		gem
USE_RUBY=	yes

PLIST_FILES=	bin/rdbg

.include <bsd.port.mk>
