# ports collection makefile for:	readline
# Date created:				10 December 2003
# Whom:					Frank Laszlo <laszlof@vonostingroup.com>
#
# $FreeBSD$
#

PORTNAME=	readline
PORTVERSION=	5.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU} \
		ftp://ftp.cwru.edu/pub/bash/
MASTER_SITE_SUBDIR=	${PORTNAME}

PATCH_SITES=	ftp://ftp.gnu.org/gnu/readline/${PORTNAME}-${PORTVERSION}-patches/ \
		ftp://ftp.cwru.edu/pub/bash/${PORTNAME}-${PORTVERSION}-patches/
PATCHFILES=	readline51-001

MAINTAINER=	laszlof@vonostingroup.com
COMMENT=	A library for editing command lines as they are typed

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

INFO=		readline rluserman history
MAN3=		readline.3 history.3

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=	Does not compile on sparc64
.endif

pre-configure:
.if !defined(WITHOUT_TERMCAP)
	${REINPLACE_CMD} "s/SHOBJ_LDFLAGS =/SHOBJ_LDFLAGS = -ltermcap/" ${WRKSRC}/shlib/Makefile.in
.endif

.include <bsd.port.post.mk>
