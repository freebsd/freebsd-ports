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

RUN_DEPENDS=	rubygem-gruff>=0<1:graphics/rubygem-gruff \
		rubygem-highline>=0:devel/rubygem-highline

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/bzconsole

.include <bsd.port.mk>
