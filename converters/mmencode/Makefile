# New ports collection makefile for:	mmencode
# Date created:		30 September 1999
# Whom:			kbyanc
#
# $FreeBSD$
#

PORTNAME=	mmencode
PORTVERSION=	2.7
CATEGORIES=	converters
MASTER_SITES=	ftp://thumper.bellcore.com/pub/nsb/
DISTNAME=	mm${PORTVERSION}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	kbyanc@posi.net

WRKSRC=		${WRKDIR}/${DISTNAME}/src/metamail

MAN1=		mmencode.1

ALL_TARGET=	mmencode

do-install:
	@cd ${WRKSRC}		&& ${INSTALL_PROGRAM} mmencode ${PREFIX}/bin
	@cd ${WRKSRC}/../man	&& ${INSTALL_MAN} mmencode.1 ${PREFIX}/man/man1
	@cd ${PREFIX}/bin	&& ${LN} -s mmencode mimencode

.include <bsd.port.mk>
