# New ports collection makefile for:    xboard
# Version required:     3.5.0
# Date created:         5 Jan 1997
# Whom:                 xaa@stack.nl
#
# $Id: Makefile,v 1.8 1996/11/18 13:58:56 asami Exp $
#

DISTNAME=       xboard-3.5.0
PKGNAME=	xboard-3.5.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	markm@FreeBSD.ORG

#BUILD_DEPENDS=  autoconf:${PORTSDIR}/devel/autoconf

GNU_CONFIGURE=  yes
CONFIGURE_ARGS= --prefix=${PREFIX}
STRIP=
MAN6=		xboard.6 cmail.6 zic2xpm.6

#pre-configure:
#	cd ${WRKSRC}; autoconf; autoheader

.include <bsd.port.mk>
