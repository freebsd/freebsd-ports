# New ports collection makefile for:	xcircuit
# Date created:		3 Apr 1998
# Whom:			giffunip@asme.org
#
# $FreeBSD$
#

PORTNAME=	xcircuit
PORTVERSION=	2.3.3.b9
PORTEPOCH=	1
CATEGORIES=	cad
MASTER_SITES=	http://bach.ece.jhu.edu/~tim/programs/xcircuit/archive/
DISTNAME=	${PORTNAME}-${PORTVERSION:R}

MAINTAINER=	ports@FreeBSD.org

RUN_DEPENDS=	gs:${PORTSDIR}/print/ghostscript-gnu
BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4

USE_BZIP2=	yes
USE_XPM=	yes
USE_IMAKE=	yes
XMKMF=		xmkmf

MAN1=		xcircuit.1

post-patch:
	@find ${WRKSRC} -type f | xargs ${PERL} -pi -e "s|__DARWIN__|__STDC__|g" 
post-install:
	@${MKDIR} ${PREFIX}/share/examples/xcircuit
	${TAR} -C ${WRKSRC}/examples --exclude CVS -cf - . | \
		${TAR} -C ${PREFIX}/share/examples/xcircuit --unlink -xf -

.include <bsd.port.mk>
