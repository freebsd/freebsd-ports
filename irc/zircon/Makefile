# New ports collection makefile for:	zircon
# Version required:	1.18.31
# Date created:		19 Aug 1995
# Whom:			jkh / pst
#
# $Id: Makefile,v 1.17 1997/09/21 04:03:59 jkh Exp $
#

DISTNAME=	zircon-1.18.56
CATEGORIES=	net tk80
MASTER_SITES=	ftp://catless.ncl.ac.uk/pub/

MAINTAINER=	ports@FreeBSD.org

IS_INTERACTIVE=	yes
NO_BUILD=	yes

# You can define USE_DPWISH if you want to run under the older
# tcl7.3/tk3.6/tclDP code.  The author strongly reccomends using
# tcl7.5/tk4.1 instead, and the tclDP wont be supported for long.
#
.if defined(USE_DPWISH) && ${USE_DPWISH} == YES
BUILD_DEPENDS=	dpwish:${PORTSDIR}/net/tclDP
RUN_DEPENDS=	dpwish:${PORTSDIR}/net/tclDP
.else
BUILD_DEPENDS=	wish8.0:${PORTSDIR}/x11/tk80
RUN_DEPENDS=	wish8.0:${PORTSDIR}/x11/tk80
.endif

do-install:
	(cd ${WRKSRC} && ./installZircon)

.include <bsd.port.mk>
