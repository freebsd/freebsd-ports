# New ports collection makefile for:	rjb
# Date created:				2011-09-11
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	rjb
PORTVERSION=	1.4.5
CATEGORIES=	java ruby
MASTER_SITES=	${MASTER_SITE_RUBYFORGE}
MASTER_SITE_SUBDIR=rjb

MAINTAINER=	arved@FreeBSD.org
COMMENT=	Call Java Code from Ruby

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=yes
USE_JAVA=	yes
GEM_ENV=	JAVA_HOME=${JAVA_HOME}
#On amd64, rjb hangs in umtxn
ONLY_FOR_ARCHS=	i386

.include <bsd.port.mk>
