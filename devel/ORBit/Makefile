# New ports collection makefile for:   orbit
# Version required:		0.3.91
# Date Created:			16 Aug 1998
# Whom:				Chia-liang Kao <clkao@CirX.ORG>
#
# $Id: Makefile,v 1.8 1998/12/26 19:23:25 vanilla Exp $
#

DISTNAME=	ORBit-0.3.91
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.jimpick.com/pub/mirrors/gnome/sources/ \
		ftp://ftp.gnome.org/pub/GNOME/sources/
#MASTER_SITES=	ftp://ftp.gnome.org/pub/ORBit/

MAINTAINER=	clkao@CirX.ORG

LIB_DEPENDS=	glib11d.1:${PORTSDIR}/devel/glib11-devel

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

CONFIGURE_ENV=	INSTALL='$${INSTALL} -c' \
		GLIB_CONFIG="${LOCALBASE}/bin/glib11d-config"
CONFIGURE_ARGS= --disable-indent

pre-install:
	@if [ ! -f ${PREFIX}/info/dir ]; then \
	${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	fi

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
