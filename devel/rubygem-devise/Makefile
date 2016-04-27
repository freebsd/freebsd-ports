# Created by: rpsfa@rit.edu
# $FreeBSD$

PORTNAME=	devise
PORTVERSION=	3.5.6
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Flexible authentication solution for Rails with Warden

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-bcrypt>=3.0:security/rubygem-bcrypt \
		rubygem-orm_adapter>=0.1:devel/rubygem-orm_adapter \
		rubygem-thread_safe>=0.1:devel/rubygem-thread_safe \
		rubygem-warden>=1.2.3:devel/rubygem-warden

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

BROKEN_RUBY23=	yes

SLAVEDIRS=	devel/rubygem-devise-rails4

OPTIONS_SINGLE=	RAILS
OPTIONS_SINGLE_RAILS=	RAILS3 RAILS4
.if defined(RAILS4)
OPTIONS_DEFAULT=	RAILS4
.else
OPTIONS_DEFAULT=	RAILS3
.endif

RAILS3_DESC=		Use Rails 3 as backend
RAILS4_DESC=		Use Rails 4 as backend

RAILS3_RUN_DEPENDS=	rubygem-railties>=3.2.6:www/rubygem-railties \
			rubygem-responders-rails3>=0:www/rubygem-responders-rails3
RAILS4_RUN_DEPENDS=	rubygem-railties4>=4.1.1:www/rubygem-railties4 \
			rubygem-responders>=0:www/rubygem-responders

post-patch:
	@${REINPLACE_CMD} -e 's|, "test/rails_app/config/routes.rb"||' ${WRKSRC}/${PORTNAME}.gemspec

.include <bsd.port.mk>
