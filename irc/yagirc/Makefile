# New ports collection makefile for:   	yagirc
# Version required:			0.65.6
# Date created:				6 July 1998
# Whom:					mph
#
# $Id: Makefile,v 1.5 1998/08/24 07:13:53 asami Exp $
#

DISTNAME=	yagirc-0.65.6
CATEGORIES=	net
MASTER_SITES=	http://www.elpaso.net/~spoon/yagirc/

MAINTAINER=	mph@freebsd.org

LIB_DEPENDS=	gtk11\\.1\\.:${PORTSDIR}/x11-toolkits/gtk11 \
		Imlib\\.1\\.7:${PORTSDIR}/graphics/imlib \
		esd\\.0\\.0:${PORTSDIR}/audio/esound

USE_GMAKE=	yes
USE_PERL5=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-gnome --disable-gtktest
CONFIGURE_ENV=	PTHREAD_LIB="-lc_r"

.include <bsd.port.mk>
