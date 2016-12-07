# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rubigen
PORTVERSION=	1.5.8
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby generic generator framework

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activesupport>=2.3.5:devel/rubygem-activesupport

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/install_rubigen_scripts \
		bin/ruby_app \
		bin/rubigen

DEPRECATED=	Depends on deprecated devel/rubygem-activesupport
EXPIRATION_DATE=	2017-01-07

.include <bsd.port.mk>
