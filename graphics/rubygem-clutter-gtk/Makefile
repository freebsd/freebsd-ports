# $FreeBSD$

PORTNAME=	clutter-gtk
PORTVERSION=	2.2.5
CATEGORIES=	graphics rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby/ClutterGTK is a Ruby binding of Clutter-GTK

LICENSE=	LGPL21 LGPL3
LICENSE_COMB=	dual

RUN_DEPENDS=	rubygem-clutter>=${PORTVERSION}:${PORTSDIR}/graphics/rubygem-clutter \
		rubygem-gtk3>=${PORTVERSION}:${PORTSDIR}/x11-toolkits/rubygem-gtk3

NO_ARCH=	yes

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
