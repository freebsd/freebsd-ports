# New ports collection makefile for:	s3switch
# Date created:				March 16, 2003
# Whom:					Bruce M Simpson <bms@spc.org>
#
# $FreeBSD$
#

PORTNAME=	s3switch
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.probo.com/timr/
DISTNAME=	s3ssrc

MAINTAINER=	bms@spc.org
COMMENT=	Enable TV-out on S3 graphics cards

USE_ZIP=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
NO_WRKSUBDIR=	yes
MAKE_ENV+=	FREEBSD=1

MAN1=		s3switch.1
PLIST_FILES=	bin/s3switch

ONLY_FOR_ARCHS=	i386

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/s3switch ${PREFIX}/bin
	${INSTALL_MAN} ${WRKDIR}/s3switch.1x ${PREFIX}/man/man1/s3switch.1

.include <bsd.port.mk>
