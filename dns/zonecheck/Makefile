# New ports collection makefile for:	zonecheck
# Date created:		10 July 2003
# Whom:	      		Janos.Mohacsi@bsd.hu
#
# $FreeBSD$
#

PORTNAME=	zonecheck
PORTVERSION=	2.0.0b7
CATEGORIES=	dns ipv6 ruby
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	Perform consistency checks on DNS zone files

RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/gtk.so:${PORTSDIR}/x11-toolkits/ruby-gtk

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_GMAKE=	yes
USE_RUBY=	yes
NO_BUILD=	yes
RUBY_VER=	1.8
MAN1=		zonecheck.1

.include <bsd.port.pre.mk>

.if ${RUBY_DEFAULT_VER} != ${RUBY_VER}
BROKEN=		Broken dependency. This might be only a package building issue. The problem is that the default Ruby version for i386 is ${RUBY_DEFAULT_VER}, while the default version for the other architectures is ${RUBY_VER}. This port requires Ruby ${RUBY_VER}. If you are using the right Ruby version, please remove the BROKEN line from the Makefile and try again.
.endif

.include <bsd.port.post.mk>
