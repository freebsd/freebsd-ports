# ports collection makefile for:	pbasic
# Version required:	2.0-950813
# Date created:		13th August 1995
# Whom:			Julian Stacey <jhs@freebsd.org>
#
# $Id: Makefile,v 1.2 1995/11/22 13:13:02 asami Exp $
#

DISTNAME=	pbasic-2.0-950813
PKGNAME=	pbasic-2.0
CATEGORIES+=	lang
MASTER_SITES=	ftp://freefall.freebsd.org/pub/FreeBSD/LOCAL_PORTS/

MAINTAINER=	asami@FreeBSD.ORG
# Ask jhs@freebsd.org if you want newer sources or author's latest e-mail
#  (which is currently "phil@gmrs.isar.de" but changes a lot)

ALL_TARGET=	freebsd
MAKEFILE=	makefile

do-configure:
	-cd ${WRKSRC} ; rm -rf termio m68000 msdos vax pyramid ns32000 \
			pdp11 cursor/cursor.dos cursor/cursor.ukc 

do-install:
	install -c -s -m 775 ${WRKSRC}/basic ${PREFIX}/bin/pbasic
	install -c -m 644 ${WRKSRC}/docs/basic.1 ${PREFIX}/man/man1/pbasic.1
.if !defined(NOMANCOMPRESS)
	gzip -9nf ${PREFIX}/man/man1/pbasic.1
.endif

.include <bsd.port.mk>
