# New ports collection makefile for:	id-utils
# Date created:		22 Aug 1996
# Whom:			pst@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	id-utils
PORTVERSION=	3.2d
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU_ALPHA}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The classic Berkeley gid/lid tools for looking up variables in code

# need to byte-compile a .el file
BUILD_DEPENDS=	emacs:${PORTSDIR}/editors/emacs20

CONFLICTS=	coreutils-* sh-utils-*

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.include <bsd.port.mk>
