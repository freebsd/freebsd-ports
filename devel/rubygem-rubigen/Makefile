# Ports collection makefile for:	rubygem-rubigen
# Date created:				8 October 2008
# Whom:					Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	rubigen
PORTVERSION=	1.5.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	A Ruby generic generator framework

RUN_DEPENDS=	rubygem-activesupport>=2.2.2:${PORTSDIR}/devel/rubygem-activesupport

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/install_rubigen_scripts	\
		bin/rubigen			\
		bin/ruby_app

.include <bsd.port.mk>
