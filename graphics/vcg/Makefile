# New ports collection makefile for: vcg
# Version required:     1.30.r3.17
# Date created: 19 February 1995
# Whom: hsu
#
# $Id$
#

DISTNAME=	vcg.1.30
PKGNAME=	vcg-1.30
CATEGORIES+=	graphics
MASTER_SITES=	ftp://ftp.cs.uni-sb.de/pub/graphics/vcg/
DISTFILES=	vcg.1.30.r3.17.tgz

pre-patch:
	@mkdir -p ${WRKSRC}/preconf/X11ccFreeBSD
	@cp ${FILESDIR}/conf ${WRKSRC}/preconf/X11ccFreeBSD
	@cp ${FILESDIR}/demo.csh ${WRKSRC}/preconf/X11ccFreeBSD
	@cp ${FILESDIR}/globals.h ${WRKSRC}/preconf/X11ccFreeBSD
	@cp ${FILESDIR}/tMakefile ${WRKSRC}/preconf/X11ccFreeBSD

.include <bsd.port.mk>
