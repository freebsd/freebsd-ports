# New ports collection makefile for:	gshar+gunshar
# Version required:	4.2.1
# Date created:		28 Dec 1994
# Whom:			ache
#
# $FreeBSD$
#

DISTNAME=	sharutils-4.2.1
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	sharutils

MAINTAINER=	ports@FreeBSD.org

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=g --disable-uucode --disable-nls
INSTALL_TARGET=	install install-man
MAN1=		gshar.1 gunshar.1

post-install:
.for info in remsync.info sharutils.info
	install-info ${PREFIX}/info/${info} ${PREFIX}/info/dir
.endfor

.include <bsd.port.mk>
