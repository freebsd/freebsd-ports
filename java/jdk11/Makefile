# New ports collection makefile for:	jdk
# Version required:     1.0.2
# Date created:		8 April 1996
# Whom:			Sujal Patel <smpatel@freebsd.org> (original)
#
# $Id: Makefile,v 1.7 1997/05/18 11:35:57 pgs Exp $
#

DISTNAME=	jdk102.11-26
PKGNAME=	jdk-1.0.2
CATEGORIES=	lang devel
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	ports@freebsd.org

NO_CDROM=	"Put copyright on packaging, etc"

NO_WRKSUBDIR=	yes

post-install:
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
