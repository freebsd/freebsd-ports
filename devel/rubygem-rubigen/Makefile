# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rubigen
PORTVERSION=	1.5.7
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	A Ruby generic generator framework

RUN_DEPENDS=	rubygem-activesupport>=2.3.5:${PORTSDIR}/devel/rubygem-activesupport \
		rubygem-i18n>=0:${PORTSDIR}/devel/rubygem-i18n

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/install_rubigen_scripts	\
		bin/rubigen			\
		bin/ruby_app

.include <bsd.port.mk>
