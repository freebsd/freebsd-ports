# Created by: Alexander Logvinov <avl@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jruby-jars
PORTVERSION=	9.2.5.0
CATEGORIES=	devel rubygems java
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	JAR files from the JRuby distribution

LICENSE=	EPL GPLv2 LGPL21
LICENSE_COMB=	dual

BUILD_DEPENDS=	jgem:lang/jruby
RUN_DEPENDS=	jruby:lang/jruby

USES=		gem
USE_JAVA=	yes
USE_RUBY=	yes

RUBYGEMBIN=	${LOCALBASE}/bin/jgem

NO_ARCH=	yes

.include <bsd.port.mk>
