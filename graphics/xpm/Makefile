# New ports collection makefile for:	xpm
# Date created:		14 September 1994
# Whom:			jkh
#
# $FreeBSD$
#

PORTNAME=	xpm
PORTVERSION=	3.4k
CATEGORIES=	graphics x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	libraries

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The X Pixmap library

USE_IMAKE=	yes
INSTALLS_SHLIB=	yes

MAN1=		cxpm.1 sxpm.1

.ifdef USE_XPM
.error You have `USE_XPM' variable defined either in environment or in make(1) arguments. Please undefine and try again.
.endif

.include <bsd.port.pre.mk>

.if ${XFREE86_VERSION} > 3
IGNORE=		is included in XFree86 >3.x
.endif

post-install:
	@ranlib ${PREFIX}/lib/libXpm.a

.include <bsd.port.post.mk>
