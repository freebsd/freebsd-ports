# New ports collection makefile for:   aftp
# Version required:	1.0
# Date created:		18th Febuary 1997
# Whom:			Joel Sutton <sutton@aardvark.apana.org.au>
#
# $Id$
#

DISTNAME=	aftp
PKGNAME=	aftp-1.0
CATEGORIES=	emulators
MASTER_SITES=	ftp://ftp.apple.asimov.net/pub/apple_II/incoming/
EXTRACT_SUFX=	.tgz

MAINTAINER=	sutton@aardvark.apana.org.au

MAN1=		aftp.1

post-install:
	${INSTALL_MAN} ${FILESDIR}/aftp.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
