# New ports collection makefile for:	wu-ftpd
# Version required:	2.4
# Date created:		18 Oct 1994
# Whom:			torstenb
#
# $Id: Makefile,v 1.1.1.1 1994/10/23 01:36:59 torstenb Exp $
#

DISTNAME=	wu-ftpd-2.4
MASTER_SITES=	ftp://ftp.wustl.edu/packages/wuarchive-ftpd/
CATEGORIES+=	networking
EXTRACT_SUFX=	.tar.Z

pre-install:
	@mkdir -p ${PREFIX}/bin
	@mkdir -p ${PREFIX}/etc
	@mkdir -p ${PREFIX}/man/man1
	@mkdir -p ${PREFIX}/man/man5
	@mkdir -p ${PREFIX}/man/man8

.include <bsd.port.mk>
