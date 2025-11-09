PORTNAME=	tmpdir
PORTVERSION=	0.3.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Extend the Dir class to manage the OS temporary file path
WWW=		https://github.com/ruby/tmpdir

LICENSE=	BSD2CLAUSE RUBY
LICENSE_COMB=	dual
LICENSE_FILE_BSD2CLAUSE=${WRKSRC}/BSDL
LICENSE_FILE_RUBY=	${WRKSRC}/COPYING

RUN_DEPENDS=	rubygem-fileutils>=0:devel/rubygem-fileutils

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
