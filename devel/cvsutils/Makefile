# New ports collection makefile for:	cvsutils
# Date created:		6 June 2000
# Whom:			knu@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	cvsutils
PORTVERSION=	2000.06.06
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.FreeBSD.org/pub/FreeBSD/local-distfiles/knu/

MAINTAINER=	knu@FreeBSD.org

USE_PERL5=	YES
NO_BUILD=	YES
WRKSRC=		${WRKDIR}/${PORTNAME}

PROGS=		cvschroot \
		cvsco \
		cvsdiff \
		cvsdiscard \
		cvspurge \
		cvsrmadm \
		cvsu

do-install:
.for f in ${PROGS}
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${PREFIX}/bin/
.endfor

.include <bsd.port.mk>
