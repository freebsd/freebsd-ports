# New ports collection makefile for:	wu-ftpd
# Version required:	2.4
# Date created:		18 Oct 1994
# Whom:			torstenb
#
# $Id: Makefile,v 1.7 1996/11/18 11:37:07 asami Exp $
#

DISTNAME=	wu-ftpd-2.4
CATEGORIES=	net
MASTER_SITES=   ftp://ftp.wustl.edu/packages/wuarchive-ftpd/ \
		http://wuarchive.wustl.edu/packages/wuarchive-ftpd/
EXTRACT_SUFX=   .tar.Z

MAINTAINER=	torstenb@FreeBSD.org

pre-install:
	@${MKDIR} ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/etc
	@${MKDIR} ${PREFIX}/man/man1
	@${MKDIR} ${PREFIX}/man/man5
	@${MKDIR} ${PREFIX}/man/man8

.include <bsd.port.mk>
