# ports collection makefile for:	readline
# Date created:				10 December 2003
# Whom:					Frank Laszlo <laszlof@vonostingroup.com>
#
# $FreeBSD$
#

PORTNAME=	readline
PORTVERSION=	5.0
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.cwru.edu/pub/bash/

PATCH_SITES=	ftp://ftp.cwru.edu/pub/bash/${PORTNAME}-${PORTVERSION}-patches/
PATCHFILES=	readline50-001 readline50-002 readline50-003 readline50-004 readline50-005

MAINTAINER=	laszlof@vonostingroup.com
COMMENT=	A library for editing command lines as they are typed

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes

INFO=		readline rluserman history
MAN3=		readline.3 history.3

pre-configure:
.if !defined(WITHOUT_TERMCAP)
	${REINPLACE_CMD} "s/SHOBJ_LDFLAGS =/SHOBJ_LDFLAGS = -ltermcap/" ${WRKSRC}/shlib/Makefile.in
.endif

.include <bsd.port.mk>
