# New ports collection makefile for:	id-utils
# Date created:		22 Aug 1996
# Whom:			pst@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	id-utils
PORTVERSION=	3.2d
CATEGORIES=	devel
MASTER_SITES=	ftp://alpha.gnu.org/pub/gnu/id-utils/

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	The classic Berkeley gid/lid tools for looking up variables in code

# need to byte-compile a .el file
BUILD_DEPENDS=	emacs:${PORTSDIR}/editors/emacs20

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.include <bsd.port.mk>
