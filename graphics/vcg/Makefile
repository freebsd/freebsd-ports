# New ports collection makefile for: vcg
# Date created: 19 February 1995
# Whom: hsu
#
# $FreeBSD$
#

PORTNAME=	vcg
PORTVERSION=	1.30
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.cs.uni-sb.de/pub/graphics/vcg/
DISTNAME=	vcg.1.30
DISTFILES=	vcg.1.30.r3.17.tgz

MAINTAINER=	ports@FreeBSD.org

USE_X_PREFIX=	yes
MANL=		pbmrot90.l pbmshift.l pbm2hp.l vcgdemomaker.l vcg.l xvcg.l

pre-patch:
	@${MKDIR} ${WRKSRC}/preconf/X11ccFreeBSD
	@${CP} ${FILESDIR}/conf ${WRKSRC}/preconf/X11ccFreeBSD
	@${CP} ${FILESDIR}/demo.csh ${WRKSRC}/preconf/X11ccFreeBSD
	@${CP} ${FILESDIR}/globals.h ${WRKSRC}/preconf/X11ccFreeBSD
	@${CP} ${FILESDIR}/tMakefile ${WRKSRC}/preconf/X11ccFreeBSD

.include <bsd.port.mk>
