# $FreeBSD$

PORTNAME=	glib2
PORTVERSION=	2.2.3
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby binding for GLib2

RUN_DEPENDS=	rubygem-pkg-config>=0:${PORTSDIR}/devel/rubygem-pkg-config

USE_GNOME=	glib20
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.pre.mk>

.if ${RUBY_VER} == 2.1
BROKEN=		Does not build with Ruby 2.1
.endif

.include <bsd.port.post.mk>
