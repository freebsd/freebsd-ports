# Created by: Michael Moll <kvedulv at kvedulv.de>
# $FreeBSD$

PORTNAME=	kafo
PORTVERSION=	1.0.5
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby framework to create installers

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	gsed:textproc/gsed \
		rubygem-ansi>=0:devel/rubygem-ansi \
		rubygem-clamp>=0.6.2:devel/rubygem-clamp \
		rubygem-highline>=1.6.21:devel/rubygem-highline \
		rubygem-kafo_parsers>=0.1.1:devel/rubygem-kafo_parsers \
		rubygem-kafo_wizards>=0:devel/rubygem-kafo_wizards \
		rubygem-logging>=0:devel/rubygem-logging \
		rubygem-powerbar>=0:devel/rubygem-powerbar

NO_ARCH=	yes
USE_RUBY=	yes
USES=		cpe gem

CPE_VENDOR=	theforeman

PLIST_FILES=	bin/kafo-configure bin/kafo-export-params bin/kafofy

.include <bsd.port.mk>
