# New ports collection makefile for:	id-utils
# Date created:		22 Aug 1996
# Whom:			pst@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	id-utils
PORTVERSION=	3.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	id-utils

MAINTAINER=	pst@FreeBSD.org

# need to byte-compile a .el file
BUILD_DEPENDS=	emacs:${PORTSDIR}/editors/emacs20

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.include <bsd.port.mk>
