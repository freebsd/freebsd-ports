# Created by: Matthias Fechner <mfechner@FreeBSD.org>

PORTNAME=	inspec-core
PORTVERSION=	4.41.20
PORTREVISION=	3
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Framework to create end-to-end infrastructure tests

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-addressable>=2.4<3:www/rubygem-addressable \
		rubygem-chef-telemetry>=1.0.8<2:sysutils/rubygem-chef-telemetry \
		rubygem-faraday14>=0.9.0<1.5:www/rubygem-faraday14 \
		rubygem-faraday_middleware>=1.0<2:www/rubygem-faraday_middleware \
		rubygem-hashie4>=3.4<5:devel/rubygem-hashie4 \
		rubygem-license-acceptance>=0.2.13<3.0:sysutils/rubygem-license-acceptance \
		rubygem-method_source>=0.8<2.0:devel/rubygem-method_source \
		rubygem-mixlib-log>=3.0<4:devel/rubygem-mixlib-log \
		rubygem-multipart-post>=2.0<3:www/rubygem-multipart-post \
		rubygem-parallel>=1.9<2:sysutils/rubygem-parallel \
		rubygem-parslet1>=1.5<2:textproc/rubygem-parslet1 \
		rubygem-pry>=0.13<1:devel/rubygem-pry \
		rubygem-rspec>=3.9<3.12:devel/rubygem-rspec \
		rubygem-rspec-its>=1.2<2:devel/rubygem-rspec-its \
		rubygem-rubyzip>=1.2.2<3:archivers/rubygem-rubyzip \
		rubygem-semverse>=3.0<4:devel/rubygem-semverse \
		rubygem-sslshake>=1.2<2:security/rubygem-sslshake \
		rubygem-thor>=0.20<2.0:devel/rubygem-thor \
		rubygem-tomlrb>=1.2<2.1:textproc/rubygem-tomlrb \
		rubygem-train-core>=3.0<4:net/rubygem-train-core \
		rubygem-tty-prompt>=0.17<1:devel/rubygem-tty-prompt \
		rubygem-tty-table>=0.10<1:devel/rubygem-tty-table

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
