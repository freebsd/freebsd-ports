# New ports collection makefile for:	vb2c
# Date created:		27 December 2001
# Whom:			Bruce M Simpson <bms@spc.org>
#
# $FreeBSD$
#

PORTNAME=	vb2c
PORTVERSION=	0.02
CATEGORIES=	devel
MASTER_SITES=	http://home.i1.net/~naken/vb2c/
DISTNAME=	vb2c-March-1999

MAINTAINER=	bms@spc.org
COMMENT=	Convert Visual Basic forms to GTK C code

WRKSRC=		${WRKDIR}/${PORTNAME}
MAKEFILE=	${FILESDIR}/Makefile

NO_MAN=
PLIST_FILES=	bin/vb2c

.include <bsd.port.pre.mk>

post-extract:
	@${RM} -f ${WRKSRC}/*.o

.include <bsd.port.post.mk>
