# New ports collection makefile for:   orbit
# Version required:		0.2.1
# Date Created:			16 Aug 1998
# Whom:				Chia-liang Kao <clkao@CirX.ORG>
#
# $Id: Makefile,v 1.2 1998/08/19 22:51:05 asami Exp $
#

DISTNAME=	ORBit-0.2.1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.gnome.org/pub/ORBit/

MAINTAINER=	clkao@CirX.ORG

LIB_DEPENDS=	glib11\\.0\\.:${PORTSDIR}/devel/glib

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

CONFIGURE_ENV=	INSTALL='$${INSTALL} -c'
CONFIGURE_ARGS= --disable-indent

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
