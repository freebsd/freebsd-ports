PORTNAME=	fpm
PORTVERSION=	1.17.0
CATEGORIES=	archivers rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Build packages for multiple platforms with great ease and sanity
WWW=		https://github.com/jordansissel/fpm

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-arr-pm>=0.0.11<0.1:devel/rubygem-arr-pm \
		rubygem-backports>=2.6.2:devel/rubygem-backports \
		rubygem-cabin>=0.9.1:devel/rubygem-cabin \
		rubygem-clamp>=1.0.0<2:devel/rubygem-clamp \
		rubygem-pleaserun>=0.0.29<0.1:devel/rubygem-pleaserun \
		rubygem-rexml>=0:textproc/rubygem-rexml \
		rubygem-stud>=0:devel/rubygem-stud

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/fpm

.include <bsd.port.mk>
