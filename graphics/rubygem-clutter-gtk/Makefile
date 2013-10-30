# $FreeBSD$

PORTNAME=	clutter-gtk
PORTVERSION=	2.0.2
CATEGORIES=	graphics rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby/ClutterGTK is a Ruby binding of Clutter-GTK

RUN_DEPENDS=	rubygem-clutter>=${PORTVERSION}:${PORTSDIR}/graphics/rubygem-clutter \
		rubygem-gtk3>=${PORTVERSION}:${PORTSDIR}/x11-toolkits/rubygem-gtk3

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
