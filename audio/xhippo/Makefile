# New ports collection makefile for:   xhippo
# Version required:                    0.8
# Date created:                                16 March 1999
# Whom:                                        Rod Taylor <tr49986@rcc.on.ca>
#
# $Id$
#

DISTNAME=      xhippo-0.8
CATEGORIES=    audio
MASTER_SITES=  http://zenchaos.netpedia.net/software/

MAINTAINER=    tr49986@rcc.on.ca

RUN_DEPENDS=   mpg123:${PORTSDIR}/audio/mpg123
LIB_DEPENDS=   gtk12.1:${PORTSDIR}/x11-toolkits/gtk12

GNU_CONFIGURE= yes
CONFIGURE_ENV= GTK_CONFIG="${X11BASE}/bin/gtk12-config"
USE_XLIB=      yes

post-install:
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
