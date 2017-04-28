# $FreeBSD$

PORTNAME=	gio2
PORTVERSION=	3.1.3
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby binding for gio 2.x

LICENSE=	LGPL21+

RUN_DEPENDS=	rubygem-glib2>=${PORTVERSION}:devel/rubygem-glib2 \
		rubygem-gobject-introspection>=${PORTVERSION}:devel/rubygem-gobject-introspection \
		rubygem-rake>=0:devel/rubygem-rake

USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
