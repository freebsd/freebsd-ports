# New ports collection makefile for:	astyle
# Version required:	1.6.0
# Date created:		31 Jan 1999
# Whom:			Don Croyle <croyle@gelemna.ft-wayne.in.us>
#
# $Id$
#

DISTNAME=	astyle_1.6.0
PKGNAME=	astyle-1.6.0
CATEGORIES= 	devel textproc
MASTER_SITES=	http://www.bigfoot.com/~davidsont/astyle/stable/src/ \
		http://www.infonex.com/~dacroyle/freebsd/
EXTRACT_SUFX=	.tgz

MAINTAINER=	croyle@gelemna.ft-wayne.in.us

BUILD_DEPENDS=	eg++:${PORTSDIR}/lang/egcs

WRKSRC=		${WRKDIR}/astyle-src
ALL_TARGET=	astyle

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/astyle ${PREFIX}/bin/

.include <bsd.port.mk>
