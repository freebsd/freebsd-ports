PORTNAME=	gio2
PORTVERSION=	3.5.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby binding of gio 2.x

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

RUN_DEPENDS=	rubygem-fiddle>=0:devel/rubygem-fiddle \
		rubygem-gobject-introspection>=${PORTVERSION}:devel/rubygem-gobject-introspection

USES=		gem gnome
USE_GNOME=	glib20
USE_RUBY=	yes

.include <bsd.port.mk>
