# New ports collection makefile for:	ScrollZ
# Version required:	1.8i5
# Date created:		10 Aug 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

DISTNAME=	ScrollZ-1.8i5-FreeBSD-3.2
PKGNAME=	scrollz-1.8i5
CATEGORIES=	irc
MASTER_SITES=	ftp://ftp.scrollz.net/pub/ScrollZ/ \
		ftp://scrollz.unixpower.com/ScrollZ/ \
		http://white.hole.org/Bins/ \
		ftp://ftp.enlighte.nu/pub/ScrollZ/Bins/
EXTRACT_SUFX=	.bz2

MAINTAINER=	andrews@technologist.com

USE_BZIP2=	YES
NO_BUILD=	YES
ONLY_FOR_ARCHS=	i386

BZIP2?=		${LOCALBASE}/bin/bzip2

pre-extract:
	@${MKDIR} ${WRKSRC}

do-extract:
	@${BZIP2} -dc ${DISTDIR}/${DISTFILES} > ${WRKSRC}/scrollz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/scrollz ${PREFIX}/bin/scrollz

.include <bsd.port.mk>
