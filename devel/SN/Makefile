# New ports collection makefile for:	SN
# Date created:			23 July 2000
# Whom:				Donald Burr <dburr@FreeBSD.ORG>
#
# $FreeBSD$
#

PORTNAME=	SN
PORTVERSION=	4.5.1
CATEGORIES=	devel
MASTER_SITES=	ftp://sources.redhat.com/pub/sourcenav/releases/ \
		ftp://sourceware.cygnus.com/pub/sourcenav/releases/ \
		ftp://ftp.sunsite.org.uk/Mirrors/sourceware.cygnus.com/pub/sourcenav/releases/ \
		ftp://ftp.ai-lab.fh-furtwangen.de/pub/mirror/sources.redhat.com/pub/sourcenav/releases/
DISTNAME=	SN451

MAINTAINER=	dburr@FreeBSD.ORG

PREFIX=		${LOCALBASE}/SN
USE_BZIP2=	yes
USE_XLIB=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/SN451

post-install:
		@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
