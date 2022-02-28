# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	pedump
PORTVERSION=	0.6.4
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Dump headers, sections, extract resources of Win32 PE exe, dll, etc

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-awesome_print>=0:devel/rubygem-awesome_print \
		rubygem-iostruct>=0.0.4:devel/rubygem-iostruct \
		rubygem-multipart-post>=2.0.0:www/rubygem-multipart-post \
		rubygem-rainbow>=0:devel/rubygem-rainbow \
		rubygem-zhexdump>=0.0.2:devel/rubygem-zhexdump

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/pedump

.include <bsd.port.mk>
