# ex:ts=8
# Ports collection makefile for:	classpath
# Date created:			Sep 1, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	classpath
PORTVERSION=	0.90
CATEGORIES=	java devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	rainer.alves@gmail.com
COMMENT=	A GNU project to create a free Java class library

BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip

USE_JAVA=	yes
USE_JIKES=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-jni --with-jikes --disable-gtk-peer
USE_GMAKE=	yes

INFO=		hacking vmintegration

.include <bsd.port.mk>
