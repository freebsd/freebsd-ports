# ex:ts=8
# New ports collection makefile for:	sfront
# Date created:			Nov 4, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	sfront
PORTVERSION=	0.85
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.cs.berkeley.edu/~lazzaro/sa/
DISTNAME=	${PORTNAME}
DIST_SUBDIR=	${PKGNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A translator that converts MP4-SA files into efficient C programs

PLIST_FILES=	bin/sfront
USE_REINPLACE=	yes
USE_BISON=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}/src
ALL_TARGET=	# empty

BROKEN=		"Distinfo incorrect"

post-patch:
	@${REINPLACE_CMD} -e "s,^CFLAGS,#CFLAGS,g" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/../bin/sfront ${PREFIX}/bin

.include <bsd.port.mk>
