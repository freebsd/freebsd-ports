# New ports collection makefile for:   xchat
# Version required:    0.2.5
# Date created:                17 Nov 1998
# Whom:                        Jim Mock <jim@phrantic.phear.net>
#
# $Id$
#

DISTNAME=      xchat-0.2.5
CATEGORIES=    net x11
MASTER_SITES=  http://users.mentasm.com/~zed/xchat/files/
EXTRACT_SUFX=  .tgz

MAINTAINER=    jim@phrantic.phear.net

BUILD_DEPENDS= gtk-config:${PORTSDIR}/x11-toolkits/gtk

do-build:
	@(cd ${WRKSRC}; make)

.include <bsd.port.mk>
