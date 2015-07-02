# Created by: rpsfa@rit.edu
# $FreeBSD$

PORTNAME=	devise
PORTVERSION=	3.5.1
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Flexible authentication solution for Rails with Warden

LICENSE=	MIT

RUN_DEPENDS=	rubygem-bcrypt>=3.0:${PORTSDIR}/security/rubygem-bcrypt \
		rubygem-orm_adapter>=0.1:${PORTSDIR}/devel/rubygem-orm_adapter \
		rubygem-thread_safe>=0.1:${PORTSDIR}/devel/rubygem-thread_safe \
		rubygem-warden>=1.2.3:${PORTSDIR}/devel/rubygem-warden

NO_ARCH=	yes

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

SLAVEDIRS=	rubygem-devise-rails4

OPTIONS_SINGLE=	RAILS
OPTIONS_SINGLE_RAILS=	RAILS3 RAILS4
.if defined(RAILS4)
OPTIONS_DEFAULT=	RAILS4
.else
OPTIONS_DEFAULT=	RAILS3
.endif

RAILS3_DESC=		Use Rails 3 as backend
RAILS4_DESC=		Use Rails 4 as backend

RAILS3_RUN_DEPENDS=	rubygem-railties>=3.2.6:${PORTSDIR}/www/rubygem-railties \
			rubygem-responders-rails3>=0:${PORTSDIR}/www/rubygem-responders-rails3
RAILS4_RUN_DEPENDS=	rubygem-railties4>=4.1.1:${PORTSDIR}/www/rubygem-railties4 \
			rubygem-responders>=0:${PORTSDIR}/www/rubygem-responders

post-patch:
	@${REINPLACE_CMD} -e 's|, "test/rails_app/config/routes.rb"||' ${WRKSRC}/${PORTNAME}.gemspec

.include <bsd.port.mk>
