# New ports collection makefile for:    xboard
# Version required:     3.4 patchlevel 1
# Date created:         2 Jan 1995
# Whom:                 swallace
#
# $Id: Makefile,v 1.6 1996/07/12 11:07:20 asami Exp $
#

DISTNAME=       xboard-3.4.pl1
PKGNAME=	xboard-3.4.1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	markm@FreeBSD.ORG

BUILD_DEPENDS=  autoconf:${PORTSDIR}/devel/autoconf

HAS_CONFIGURE=  yes
CONFIGURE_ARGS= --prefix=${PREFIX}
STRIP=

pre-configure:
	cd ${WRKSRC}; autoconf; autoheader

.include <bsd.port.mk>
