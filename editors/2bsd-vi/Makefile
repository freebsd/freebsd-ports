# New ports collection makefile for:	2bsd-vi
# Date created:			2004-07-12
# Whom:				David Thiel <lx@redundancy.redundancy.org>
#
# $FreeBSD$
#

PORTNAME=	vi
PORTVERSION=	050325
CATEGORIES=	editors
MASTER_SITES=	SF/ex-${PORTNAME}/ex-${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	2bsd-
DISTNAME=	ex-${PORTVERSION}

MAINTAINER=	lx@redundancy.redundancy.org
COMMENT=	The original vi editor, updated to run on modern OSes

USE_BZIP2=	yes

PRESERVEDIR=	/var/preserve/${UNIQUENAME}
PLIST_SUB=	PRESERVEDIR="${PRESERVEDIR}"

MAN1=	ex.1 vi.1
MLINKS=	ex.1 edit.1  vi.1 vedit.1  vi.1 view.1

post-patch:
.for f in Makefile ex.1 expreserve.c exrecover.c vi.1
	@${REINPLACE_CMD} -e 's|/var/preserve|${PRESERVEDIR}|' ${WRKSRC}/${f}
.endfor

.include <bsd.port.mk>
