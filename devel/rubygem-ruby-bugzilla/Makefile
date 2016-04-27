# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ruby-bugzilla
PORTVERSION=	0.6.4
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Access to Bugzilla through WebService APIs in Ruby

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	rubygem-gruff>=0:graphics/rubygem-gruff \
		rubygem-highline>=0:devel/rubygem-highline

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/bzconsole

.include <bsd.port.mk>
