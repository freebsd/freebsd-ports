# $FreeBSD$

PORTNAME=	echoe
PORTVERSION=	4.5
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Rake tasks for docs, extension compiling, testing, and deployment

RUN_DEPENDS=	rubygem-rubyforge>=0:${PORTSDIR}/devel/rubygem-rubyforge \
		rubygem-gemcutter>=0:${PORTSDIR}/devel/rubygem-gemcutter \
		rubygem-highline>=0:${PORTSDIR}/devel/rubygem-highline \
		rubygem-allison>=0:${PORTSDIR}/devel/rubygem-allison

USE_RUBY=		yes
USE_RUBYGEMS=		yes
USE_RAKE=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
