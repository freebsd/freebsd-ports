# New ports collection makefile for:   orbit
# Version required:		0.3.0
# Date Created:			16 Aug 1998
# Whom:				Chia-liang Kao <clkao@CirX.ORG>
#
# $Id: Makefile,v 1.4 1998/09/22 23:31:11 asami Exp $
#

DISTNAME=	ORBit-0.3.0
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.gnome.org/pub/ORBit/

MAINTAINER=	clkao@CirX.ORG

LIB_DEPENDS=	glib11.0:${PORTSDIR}/devel/glib

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

CONFIGURE_ENV=	INSTALL='$${INSTALL} -c'
CONFIGURE_ARGS= --disable-indent

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
