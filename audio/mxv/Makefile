# New ports collection makefile for:	mxv
# Version required:	1.10
# Date created:		17 March 1997
# Whom:			davidn@blaze.net.au
#
# $Id: Makefile,v 1.6 1998/09/28 01:51:38 steve Exp $
#

DISTNAME=	mxv-v1.10-source
PKGNAME=	mxv-1.10
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.funet.fi/pub/sci/audio/mxv/

MAINTAINER=	davidn@blaze.net.au

BUILD_DEPENDS=	${LOCALBASE}/interviews/bin/FREEBSD/ivmkmf:${PORTSDIR}/x11-toolkits/iv

NO_WRKSUBDIR=	yes
USE_IMAKE=	yes
MAKE_ENV=	CPU=FREEBSD
#ivmkmf -a (with makedepend) not recommended by documentation
XMKMF=		env ${MAKE_ENV} ${LOCALBASE}/interviews/bin/FREEBSD/ivmkmf; \
		env ${MAKE_ENV} make Makefiles

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/FREEBSD/mxv ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/MiXViews.res ${PREFIX}/lib/X11/app-defaults/MiXViews

.include <bsd.port.mk>
