# $FreeBSD$

PORTNAME=	pleaserun
PORTVERSION=	0.0.31
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Tool to generate startup scripts

LICENSE=	APACHE20

RUN_DEPENDS=	rubygem-cabin>=0:devel/rubygem-cabin \
		rubygem-clamp>=0:devel/rubygem-clamp \
		rubygem-dotenv>=0:misc/rubygem-dotenv \
		rubygem-insist>=0:devel/rubygem-insist \
		rubygem-mustache>=0.99.8:devel/rubygem-mustache \
		rubygem-stud>=0:devel/rubygem-stud

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/please-manage-user bin/pleaserun

.include <bsd.port.mk>
