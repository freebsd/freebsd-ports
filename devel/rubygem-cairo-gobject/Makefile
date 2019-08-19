# $FreeBSD$

PORTNAME=	cairo-gobject
PORTVERSION=	3.3.7
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby binding for cairo-gobject

LICENSE=	LGPL21+

RUN_DEPENDS=	rubygem-cairo>=1.16.2:graphics/rubygem-cairo \
		rubygem-glib2>=${PORTVERSION}:devel/rubygem-glib2

USES=		gem gnome
USE_GNOME=	cairo glib20
USE_RUBY=	yes

.include <bsd.port.mk>
