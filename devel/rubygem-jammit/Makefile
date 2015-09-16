# Created by: rpsfa@rit.edu
# $FreeBSD$

PORTNAME=	jammit
PORTVERSION=	0.6.6
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Industrial strength asset packaging library for Rails

LICENSE=	MIT

RUN_DEPENDS=	rubygem-cssmin>=1.0.3:${PORTSDIR}/textproc/rubygem-cssmin \
		rubygem-jsmin>=1.0.1:${PORTSDIR}/textproc/rubygem-jsmin

NO_ARCH=	yes

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/jammit

.include <bsd.port.mk>
