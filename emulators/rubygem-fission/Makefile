PORTNAME=	fission
PORTVERSION=	0.5.0
PORTREVISION=	1
CATEGORIES=	emulators rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Utility to manage VMware Fusion VMs from the command line

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-CFPropertyList>=2.2:devel/rubygem-CFPropertyList

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/fission

.include <bsd.port.mk>
