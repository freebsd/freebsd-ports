# New ports collection makefile for:	aacplusenc
# Date created:				28 July 2007
# Whom:					Pav Lucistnik <pav@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	aacplusenc
PORTVERSION=	0.7
CATEGORIES=	audio
MASTER_SITES=	http://openjlabs.com/tl_files/openjlabs/downloads/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	pav@FreeBSD.org
COMMENT=	aacPlus v2 command-line encoder

USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

RESTRICTED=	unclear legal status, probably need licenses from 3GPP, Via Licensing and Coding Technologies

PLIST_FILES=	bin/aacplusenc

post-patch:
	@${REINPLACE_CMD} -e 's|-O3 -ftree-vectorize|${CFLAGS}|' ${WRKSRC}/Makefile

.include <bsd.port.mk>
