# New ports collection makefile for:   	yagirc
# Version required:			0.65.7
# Date created:				6 July 1998
# Whom:					mph
#
# $Id: Makefile,v 1.11 1998/11/10 00:03:17 asami Exp $
#

DISTNAME=	yagirc-0.65.7
CATEGORIES=	net
MASTER_SITES=	http://www.elpaso.net/~spoon/yagirc/

MAINTAINER=	mph@freebsd.org

LIB_DEPENDS=	gtk11.1:${PORTSDIR}/x11-toolkits/gtk11 \
		Imlib.1:${PORTSDIR}/graphics/imlib \
		esd.1:${PORTSDIR}/audio/esound

BROKEN=		build

USE_GMAKE=	yes
USE_PERL5=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-gnome --disable-gtktest
CONFIGURE_ENV=	PTHREAD_LIB="-lc_r"

.include <bsd.port.mk>
