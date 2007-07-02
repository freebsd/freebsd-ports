# New ports collection makefile for:    pfe-devel
# Date created:         29 October 2000
# Whom:                 patrick
#
# $FreeBSD$
#

PORTNAME=	pfe
PORTVERSION=	0.32.94
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Implementation of ANSI Forth

LATEST_LINK=	pfe-devel

USE_AUTOTOOLS=	libtool:15
USE_PERL5_BUILD=yes
USE_GNOME=	gnometarget lthack
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
LIBTOOLFILES=	pfe/configure
CONFIGURE_ARGS=	--mandir=${PREFIX}/man

MAN1=		pfe.1 pfe-config.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700042
BROKEN=		Does not compile with GCC 4.2
.endif

.include <bsd.port.post.mk>
