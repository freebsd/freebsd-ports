# New ports collection makefile for:	zircon
# Version required:	1.17p3
# Date created:		19 Aug 1995
# Whom:			jkh / pst
#
# $Id: Makefile,v 1.6 1995/11/27 04:06:03 asami Exp $
#

DISTNAME=	zircon-1.17p3
CATEGORIES+=	net
MASTER_SITES=	ftp://catless.ncl.ac.uk/pub/

#
# You can define USE_DPWISH if you want to run under the older
# tcl7.3/tk3.6/tclDP code.  The author strongly reccomends using
# tcl7.5/tk4.1 instead, and the tclDP wont be supported for long.
#
.if defined(USE_DPWISH) && ${USE_DPWISH} == YES && exists(${PREFIX}/bin/dpwish)
BUILD_DEPENDS=	dpwish:${PORTSDIR}/net/tclDP
RUN_DEPENDS=	dpwish:${PORTSDIR}/net/tclDP
MAKE_ENV=	WISH=${PREFIX}/bin/dpwish
.else
BUILD_DEPENDS=	wish4.1:${PORTSDIR}/x11/tk41
RUN_DEPENDS=	wish4.1:${PORTSDIR}/x11/tk41
MAKE_ENV=	WISH=${PREFIX}/bin/wish4.1
.endif

MAKEFILE=	Makefile.FreeBSD

pre-patch:
	cp ${WRKSRC}/Makefile.Linux ${WRKSRC}/Makefile.FreeBSD

.include <bsd.port.mk>
