# ex:ts=8
# Ports collection makefile for:	multivideo
# Date created:			Oct 18, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	multivideo
PORTVERSION=	0.1.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.lis.inpg.fr/scientifique/bonnaud/multivideo/download/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org

USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
USE_GMAKE=	yes
ALL_TARGET=	# empty

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/multivideo ${PREFIX}/bin

.include <bsd.port.mk>
