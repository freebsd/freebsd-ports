# New ports collection makefile for:   libobjects
# Version required:    0.1.19
# Date created:        21 April 1998
# Whom:                Yukihiro Nakai <Nakai@technologist.com>
#
# $FreeBSD$
#

DISTNAME=	libobjects-0.1.19
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	libobjects

MAINTAINER=	nacai@iname.com

GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>
.if ${OSVERSION} > 400002
BROKEN=		no objc header files
.endif

.include <bsd.port.post.mk>
