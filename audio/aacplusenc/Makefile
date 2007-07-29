# New ports collection makefile for:	aacplusenc
# Date created:				28 July 2007
# Whom:					Pav Lucistnik <pav@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	aacplusenc
PORTVERSION=	0.6
CATEGORIES=	audio
MASTER_SITES=	http://teknoraver.campuslife.it/software/

MAINTAINER=	pav@FreeBSD.org
COMMENT=	aacPlus v2 command-line encoder

USE_BZIP2=	yes
USE_GMAKE=	yes
ONLY_FOR_ARCHS=	i386
ONLY_FOR_ARCHS_REASON=	Produces badly sounding files on amd64
RESTRICTED=	unclear legal status, probably need licenses from 3GPP, Via Licensing and Coding Technologies

PLIST_FILES=	bin/aacplusenc

post-patch:
	@${REINPLACE_CMD} -e 's|-O3 -ftree-vectorize|${CFLAGS}|' ${WRKSRC}/Makefile

.include <bsd.port.mk>
