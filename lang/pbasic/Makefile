# ports collection makefile for:	pbasic
# Date created:		13th August 1995
# Whom:			Julian Stacey <jhs@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	pbasic
PORTVERSION=	2.0
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	trevor
DISTNAME=	${PORTNAME}-${PORTVERSION}-950813

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Phil Cockroft's Basic Interpreter (previously Rabbit Basic)
# Ask jhs@freebsd.org if you want newer sources or author's latest e-mail
#  (which is currently "phil@gmrs.isar.de" but changes a lot)

ALL_TARGET=	freebsd
MAKEFILE=	makefile
MAN1=		pbasic.1
PLIST_FILES=	bin/pbasic

do-configure:
	-cd ${WRKSRC} ; ${RM} -rf termio m68000 msdos vax pyramid ns32000 \
			pdp11 cursor/cursor.dos cursor/cursor.ukc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/basic ${PREFIX}/bin/pbasic
	${INSTALL_MAN} ${WRKSRC}/docs/basic.1 ${PREFIX}/man/man1/pbasic.1

.include <bsd.port.mk>
