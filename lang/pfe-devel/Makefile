# New ports collection makefile for:    pfe-devel
# Date created:         29 October 2000
# Whom:                 patrick
#
# $FreeBSD$
#

PORTNAME=	pfe
PORTVERSION=	0.32.94
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Implementation of ANSI Forth

LATEST_LINK=	pfe-devel

USE_PERL5_BUILD=yes
USE_GNOME=	gnometarget lthack
USE_GMAKE=	yes
USE_LIBTOOL_VER=15
LIBTOOLFILES=	pfe/configure
LIBTOOLFLAGS=	# none
CONFIGURE_ARGS=	--mandir=${PREFIX}/man

MAN1=		pfe.1 pfe-config.1

.include <bsd.port.mk>
