# New ports collection makefile for:   orbit
# Version required:		0.3.98
# Date Created:			16 Aug 1998
# Whom:				Chia-liang Kao <clkao@CirX.ORG>
#
# $Id: Makefile,v 1.13 1999/01/31 16:57:13 vanilla Exp $
#

DISTNAME=	ORBit-0.3.98
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	ORBit

MAINTAINER=	clkao@CirX.ORG

LIB_DEPENDS=	glib11d.2:${PORTSDIR}/devel/glib11-devel

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

CONFIGURE_ENV=	GLIB_CONFIG="${LOCALBASE}/bin/glib11d-config"
CONFIGURE_ARGS= --disable-indent

pre-install:
	@if [ ! -f ${PREFIX}/info/dir ]; then \
	${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	fi

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
