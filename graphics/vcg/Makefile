# New ports collection makefile for: vcg
# Version required:     1.30.r3.17
# Date created: 19 February 1995
# Whom: hsu
#
# $Id: Makefile,v 1.6 1996/11/18 14:01:03 asami Exp $
#

DISTNAME=	vcg.1.30
PKGNAME=	vcg-1.30
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.cs.uni-sb.de/pub/graphics/vcg/
DISTFILES=	vcg.1.30.r3.17.tgz

USE_X_PREFIX=	yes
MANL=		pbmrot90.l pbmshift.l pbm2hp.l vcgdemomaker.l vcg.l xvcg.l

pre-patch:
	@mkdir -p ${WRKSRC}/preconf/X11ccFreeBSD
	@cp ${FILESDIR}/conf ${WRKSRC}/preconf/X11ccFreeBSD
	@cp ${FILESDIR}/demo.csh ${WRKSRC}/preconf/X11ccFreeBSD
	@cp ${FILESDIR}/globals.h ${WRKSRC}/preconf/X11ccFreeBSD
	@cp ${FILESDIR}/tMakefile ${WRKSRC}/preconf/X11ccFreeBSD

.include <bsd.port.mk>
