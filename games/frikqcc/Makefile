# New ports collection makefile for:	FrikQCC
# Date created:				16 Mar 2005
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	frikqcc
PORTVERSION=	2.6
CATEGORIES=	games devel
MASTER_SITES=	http://wiki.quakesrc.org/files/ \
		http://freebsd.nsu.ru/distfiles/
DISTNAME=	${PORTNAME:S/qcc//}${PORTVERSION:S/.//g}src

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Advanced QuakeC compiler/decompiler

USE_ZIP=	yes

MAKEFILE=	${FILESDIR}/Makefile

PLIST_FILES=	bin/frikqcc bin/frikqcdec

do-install:
.for p in ${PLIST_FILES:S/bin\///g}
	${INSTALL_PROGRAM} ${WRKSRC}/${p} ${PREFIX}/bin
.endfor

.include <bsd.port.mk>
