# New ports collection makefile for:    miniscrib
# Date created:         27 December 2001
# Whom:                 Bruce M Simpson <bms@spc.org>
#
# $FreeBSD$
#

PORTNAME=       miniscrib
PORTVERSION=    0.1
CATEGORIES=     graphics
MASTER_SITES=   http://www.mallum.com/ipaq/tarballs/
DISTNAME=	miniscrib-ipaq
EXTRACT_SUFX=	.tgz

MAINTAINER=     bms@spc.org

BROKEN=		"Does not fetch"

WRKSRC=         ${WRKDIR}/${PORTNAME}
USE_X11_PREFIX=	yes
USE_XPM=	yes

NO_MAN=

post-extract:
	${RM} -f ${WRKSRC}/miniscrib

# Configure is a no-op for this port.
do-configure:

.include <bsd.port.mk>
