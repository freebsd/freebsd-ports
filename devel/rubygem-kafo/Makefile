# Created by: Michael Moll <kvedulv at kvedulv.de>
# $FreeBSD$

PORTNAME=	kafo
PORTVERSION=	0.6.12
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mmoll@FreeBSD.org
COMMENT=	Ruby framework to create installers

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-clamp>=0.6.2:${PORTSDIR}/devel/rubygem-clamp \
		rubygem-highline>=1.6.21:${PORTSDIR}/devel/rubygem-highline \
		rubygem-logging>=1.8.1:${PORTSDIR}/devel/rubygem-logging \
		rubygem-powerbar>=1.0.11:${PORTSDIR}/devel/rubygem-powerbar \
		rubygem-kafo_parsers>=0.0.3:${PORTSDIR}/devel/rubygem-kafo_parsers \
		gsed:${PORTSDIR}/textproc/gsed

USES=		cpe
NO_ARCH=	yes

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

CPE_VENDOR=	theforeman

PLIST_FILES=	bin/kafo-configure bin/kafo-export-params bin/kafofy

.include <bsd.port.mk>
