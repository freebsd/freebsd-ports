# New ports collection makefile for: elftoaout
# Version required:	2.0
# Date created:         3 Jul 1998
# Whom:                 kchowksey@hss.hns.com
#
# $FreeBSD$
#

DISTNAME=	elftoaout-2.0
CATEGORIES=	devel
MASTER_SITES=   ftp://sunsite.mff.cuni.cz/OS/Linux/Sparc/local/ultra/
EXTRACT_SUFX=	.tgz

MAINTAINER=	kchowksey@hss.hns.com

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/elftoaout ${PREFIX}/bin

.include <bsd.port.mk>
