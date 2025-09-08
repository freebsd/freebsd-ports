PORTNAME=	pleaserun
PORTVERSION=	0.0.33
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Tool to generate startup scripts
WWW=		https://github.com/jordansissel/pleaserun

LICENSE=	APACHE20

RUN_DEPENDS=	rubygem-cabin>=0:devel/rubygem-cabin \
		rubygem-clamp>=0:devel/rubygem-clamp \
		rubygem-dotenv>=2:misc/rubygem-dotenv \
		rubygem-insist>=0:devel/rubygem-insist \
		rubygem-mustache>=0.99.8:devel/rubygem-mustache \
		rubygem-stud>=0:devel/rubygem-stud

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/please-manage-user bin/pleaserun

.include <bsd.port.mk>
