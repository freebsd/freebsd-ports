# New ports collection makefile for:	zircon
# Version required:	1.18.31
# Date created:		19 Aug 1995
# Whom:			jkh / pst
#
# $Id: Makefile,v 1.14 1997/07/14 12:50:14 jkh Exp $
#

DISTNAME=	zircon-1.18.31
CATEGORIES=	net tk41
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
BUILD_DEPENDS=	wish4.1:${PORTSDIR}/x11/tk41
RUN_DEPENDS=	wish4.1:${PORTSDIR}/x11/tk41
.endif

install:
	(cd ${WRKSRC} && ./installZircon)

.include <bsd.port.mk>
