# New ports collection makefile for:	makedepend
# Date created:				August 15th 1997
# Whom:					Ian Vaudrey <i.vaudrey@bigfoot.com>
#
# $FreeBSD$
#

PORTNAME=	makedepend
PORTVERSION=	2000.12.28
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.andrew.cmu.edu/pub/cyrus-mail/%SUBDIR%/
MASTER_SITE_SUBDIR=. OLD-VERSIONS/imap
DISTNAME=	cyrus-imapd-2.0.9

MAINTAINER=	roam@FreeBSD.org
COMMENT=	A dependency generator for makefiles

WRKSRC=		${WRKDIR}/${DISTNAME}/makedepend
GNU_CONFIGURE=	YES

MAN1=		makedepend.1
PLIST_FILES=	bin/makedepend

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/makedepend ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/mkdepend.man ${PREFIX}/man/man1/makedepend.1

.include <bsd.port.mk>
