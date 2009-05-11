# ports collection makefile for:	readline
# Date created:				10 December 2003
# Whom:					Frank Laszlo <laszlof@vonostingroup.com>
#
# $FreeBSD$
#

PORTNAME=	readline
PORTVERSION=	6.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU} \
		ftp://ftp.cwru.edu/pub/bash/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	EitanAdlerList@gmail.com
COMMENT=	A library for editing command lines as they are typed

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

INFO=		readline rluserman history
MAN3=		readline.3 history.3

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
EXTRA_PATCHES+=	${FILESDIR}/support_shobj-conf.diff
.endif

pre-configure:
.if !defined(WITHOUT_TERMCAP)
	${REINPLACE_CMD} "s/SHOBJ_LDFLAGS =/SHOBJ_LDFLAGS = -ltermcap/" ${WRKSRC}/shlib/Makefile.in
.endif

.include <bsd.port.post.mk>
