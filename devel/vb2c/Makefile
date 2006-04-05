# New ports collection makefile for:	vb2c
# Date created:		27 December 2001
# Whom:			Bruce M Simpson <bms@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vb2c
PORTVERSION=	0.02
CATEGORIES=	devel
MASTER_SITES=	http://www.mikekohn.com/programs/
DISTNAME=	vb2c-March-1999

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert Visual Basic forms to GTK C code

WRKSRC=		${WRKDIR}/${PORTNAME}
MAKEFILE=	${FILESDIR}/Makefile

PLIST_FILES=	bin/vb2c

post-extract:
	@${RM} -f ${WRKSRC}/*.o

.include <bsd.port.mk>
