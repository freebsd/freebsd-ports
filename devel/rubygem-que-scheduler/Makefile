PORTNAME=	que-scheduler
PORTVERSION=	10.1.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Lightweight cron scheduler for the Que async job worker
WWW=		https://github.com/hlascelles/que-scheduler

LICENSE=	MIT

BROKEN_RUBY33=	yes
BROKEN_RUBY34=	yes

xRUN_DEPENDS=	rubygem-activesupport81>=8.0:devel/rubygem-activesupport81 \
		rubygem-fugit>=1.11.1<2:devel/rubygem-fugit \
		rubygem-que>=2.0<3.0:devel/rubygem-que \
		rubygem-sorbet-runtime>=0.5:devel/rubygem-sorbet-runtime

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
