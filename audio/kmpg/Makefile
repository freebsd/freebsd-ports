# New ports collection makefile for:   kmpg
# Version required:    0.4.3a
# Date created:        23 May 1998
# Whom:                Hans Petter Bieker <hanspb@persbraten.vgs.no>
#
# $Id: Makefile,v 1.10 1999/03/09 06:22:44 fenner Exp $
#

DISTNAME=	kmpg-0.4.3a
CATEGORIES=	audio kde
MASTER_SITES=	http://www.freebsd.org/~tom/distfiles/

MAINTAINER=	tom@FreeBSD.ORG

LIB_DEPENDS=	kdecore.1:${PORTSDIR}/x11/kdelibs \
		kdeui.1:${PORTSDIR}/x11/kdelibs

USE_QT=		yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	CXXFLAGS="${CXXFLAGS}" \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}"

.include <bsd.port.mk>
