# New ports collection makefile for:	wmtimebomb
# Version required:	0.6
# Date created:		10 August 1998
# Whom:			Thomas Gellekum <tg@FreeBSD.ORG>
#
# $Id: Makefile,v 1.3 1998/09/17 00:32:33 asami Exp $

DISTNAME=	wmtimebomb.6
PKGNAME=	wmtimebomb-0.1.6
CATEGORIES=	games windowmaker
MASTER_SITES=	http://www.gpf.or.th/~mhz/wmtimebomb/

MAINTAINER=	ports@FreeBSD.ORG

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm
BUILD_DEPENDS=	${PREFIX}/lib/libWMaker.a:${PORTSDIR}/x11-wm/windowmaker

WRKSRC=		${WRKDIR}/wmtimebomb
USE_IMAKE=	yes
NO_INSTALL_MANPAGES=	yes

.include <bsd.port.mk>
