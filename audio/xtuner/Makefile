# New ports collection makefile for:	Xtuner-2.1
# Version required:	2.1
# Date created:		19 December 96
# Whom:			Lars Koeller <Lars.Koeller@Uni-Bielefeld.DE>
#
# $Id: Makefile,v 1.6 1998/11/03 00:38:26 jseger Exp $
#

DISTNAME=	Xtuner-2.1
PKGNAME=	xtuner-2.1
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.uni-bielefeld.de/pub/systems/FreeBSD/lkoeller/

MAINTAINER=	Lars.Koeller@Uni-Bielefeld.DE

LIB_DEPENDS=	xforms.0:${PORTSDIR}/x11-toolkits/xforms \
		Xpm.4:${PORTSDIR}/graphics/xpm

# depends on xforms
ONLY_FOR_ARCHS=	i386

USE_IMAKE=	YES
NO_INSTALL_MANPAGES=	YES

.include <bsd.port.mk>
