# ports collection makefile for:	readline
# Date created:				10 December 2003
# Whom:					Frank Laszlo <laszlof@vonostingroup.com>
#
# $FreeBSD$
#

PORTNAME=	readline
PORTVERSION=	4.3
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.cwru.edu/pub/bash/

PATCHFILES=     readline43-001 readline43-002 readline43-003 readline43-004 readline43-005
PATCH_SITES=    ${MASTER_SITE_GNU}/${PORTNAME}
PATCH_SITE_SUBDIR=	${PORTNAME}/${PORTNAME}-${PORTVERSION}-patches

MAINTAINER=	laszlof@vonostingroup.com
COMMENT=	A library for editing command lines as they are typed

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

INFO=		readline rluserman history
MAN3=		readline.3 history.3

.include <bsd.port.mk>
