# New ports collection makefile for:	sox - Sound Exchange
# Version required:	10p11
# Date created:		17 Oct 1994
# Whom:			torstenb
#
# $Id: Makefile,v 1.5 1995/05/05 20:43:47 torstenb Exp $
#

DISTNAME=	sox10p11
PKGNAME=	sox-10.11
CATEGORIES+=	audio
MASTER_SITES=	ftp://nic.switch.ch/software/sources/audio/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	torstenb@FreeBSD.ORG

post-install:
	gzip -9nf ${PREFIX}/man/man1/sox.1

.include <bsd.port.mk>
