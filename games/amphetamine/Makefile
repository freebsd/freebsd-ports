# New ports collection makefile for:	amphetamine
# Date created:		6 March 2000
# Whom:			Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	amphetamine
PORTVERSION=	0.8.8
CATEGORIES=	graphics
MASTER_SITES=	http://www.dataway.ch/~lukasl/amph/files/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-data-${DATAVERSION}${EXTRACT_SUFX}

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=  	SDL-1.0.2:${PORTSDIR}/devel/sdl \
		Xpm.4:${PORTSDIR}/graphics/xpm

DATAVERSION=	0.8.6

USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes

post-install:
		@(cd ${WRKDIR}/amph && ${TAR} -c -f - * ) \
			| (cd ${PREFIX}/share/amph && ${TAR} --unlink -x -f -)

.include <bsd.port.mk>
