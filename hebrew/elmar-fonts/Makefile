# New ports collection makefile for:    elmar-fonts
# Date created:        23 March 2000
# Whom:                nadav@cs.technion.ac.il
#
# $FreeBSD$
#

PORTNAME=	elmar-fonts
PORTVERSION=	3.3
CATEGORIES=	hebrew x11-fonts
MASTER_SITES=	ftp://ftp.elmar.co.il/Portable/fonts/
DISTNAME=	H.fonts
EXTRACT_SUFX=   .tar.Z

MAINTAINER=	nadav@cs.technion.ac.il
COMMENT=	A collection of Hebrew fonts from El-Mar software Ltd

NO_WRKSUBDIR=	yes
USE_X_PREFIX=	yes
NO_BUILD=	yes

do-install:
	${MKDIR} ${PREFIX}/lib/X11/fonts/hebrew
	${TAR} -C ${PREFIX}/lib/X11/fonts/hebrew -xZpf \
		${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}
post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
