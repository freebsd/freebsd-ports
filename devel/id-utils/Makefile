# New ports collection makefile for:	id-utils
# Version required:	3.2
# Date created:		22 Aug 1996
# Whom:			pst@freebsd.org
#
# $Id: Makefile,v 1.3 1996/11/17 02:32:06 asami Exp $
#

DISTNAME=	id-utils-3.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	pst@FreeBSD.ORG

# need to byte-compile a .el file
BUILD_DEPENDS=	emacs:${PORTSDIR}/editors/emacs

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.include <bsd.port.mk>
