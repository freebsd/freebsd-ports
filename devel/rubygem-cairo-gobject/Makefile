# $FreeBSD$

PORTNAME=	cairo-gobject
PORTVERSION=	2.2.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby binding for cairo-gobject

LICENSE=	LGPL21 LGPL3
LICENSE_COMB=	dual

RUN_DEPENDS=	rubygem-cairo>=1.12.5:${PORTSDIR}/graphics/rubygem-cairo \
		rubygem-glib2>=${PORTVERSION}:${PORTSDIR}/devel/rubygem-glib2

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
