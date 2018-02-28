# $FreeBSD$

PORTNAME=	fpm
PORTVERSION=	1.9.3
PORTREVISION=	1
CATEGORIES=	archivers rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Build packages for multiple platforms with great ease and sanity

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-arr-pm>=0.0.10:devel/rubygem-arr-pm \
		rubygem-cabin>=0.6.0:devel/rubygem-cabin \
		rubygem-childprocess>=0:devel/rubygem-childprocess \
		rubygem-clamp>=1.0.0:devel/rubygem-clamp \
		rubygem-ffi>=0:devel/rubygem-ffi \
		rubygem-json1>=1.7.7:devel/rubygem-json1 \
		rubygem-pleaserun>=0.0.29:devel/rubygem-pleaserun \
		rubygem-ruby-xz>=0:archivers/rubygem-ruby-xz \
		rubygem-stud>=0:devel/rubygem-stud

NO_ARCH=	yes
REINPLACE_ARGS=	-i ''
USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/fpm

post-patch:
	@${REINPLACE_CMD} -e '/clamp/ s|1\.0\.0|1.0|' ${WRKSRC}/${GEMSPEC}
# Remove backports
	@${REINPLACE_CMD} -e '/backports/d' ${WRKSRC}/${GEMSPEC}
	@${REINPLACE_CMD} -e '/require "backports"/d' ${WRKSRC}/lib/fpm/package.rb ${WRKSRC}/lib/fpm/package/*.rb

.include <bsd.port.mk>
