# New ports collection makefile for:   orbit
# Version required:		0.4.0
# Date Created:			16 Aug 1998
# Whom:				Chia-liang Kao <clkao@CirX.ORG>
#
# $Id: Makefile,v 1.16 1999/04/08 18:08:31 steve Exp $
#

DISTNAME=	ORBit-0.4.2
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/ORBit

MAINTAINER=	clkao@CirX.ORG

LIB_DEPENDS=	glib12.1:${PORTSDIR}/devel/glib12

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

CONFIGURE_ENV=	GLIB_CONFIG="${LOCALBASE}/bin/glib12-config"
CONFIGURE_ARGS= --disable-indent

pre-install:
	@if [ ! -f ${PREFIX}/info/dir ]; then \
	${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	fi

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
