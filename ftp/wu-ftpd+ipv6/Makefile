# New ports collection makefile for:	wu-ftpd
# Version required:	2.4
# Date created:		18 Oct 1994
# Whom:			torstenb
#
# $Id: Makefile,v 1.5 1996/03/30 13:09:19 ache Exp $
#

DISTNAME=	wu-ftpd-2.4
CATEGORIES+=	net
MASTER_SITES=   ftp://ftp.wustl.edu/packages/wuarchive-ftpd/ \
		http://wuarchive.wustl.edu/packages/wuarchive-ftpd/
EXTRACT_SUFX=   .tar.Z

pre-install:
	@mkdir -p ${PREFIX}/bin
	@mkdir -p ${PREFIX}/etc
	@mkdir -p ${PREFIX}/man/man1
	@mkdir -p ${PREFIX}/man/man5
	@mkdir -p ${PREFIX}/man/man8

.include <bsd.port.mk>
