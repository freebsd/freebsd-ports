# New ports collection makefile for:	fb
# Version required:			1.5
# Date created:				Oct 15, 1999
# Whom:					Mikhail Teterin
#
# $FreeBSD$
#

DISTNAME=	fb
PKGNAME=	fb-1.5
CATEGORIES= 	editors
MASTER_SITES=	http://home.MHO.net/JSwaby/
EXTRACT_SUFX=	_tar.gz

MAINTAINER=	mi@aldan.algebra.com

NO_WRKSUBDIR=	Yes

MAN1=		fb.1
MANCOMPRESSED=	maybe

do-configure:
	${SED} 's|UL|${PREFIX}|' < ${FILESDIR}/Makefile.in > ${WRKSRC}/Makefile

.include <bsd.port.mk>
