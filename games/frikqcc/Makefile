# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	frikqcc
PORTVERSION=	2.6
CATEGORIES=	games devel
MASTER_SITES=	http://wiki.quakesrc.org/files/ \
		http://freebsd.nsu.ru/distfiles/
DISTNAME=	${PORTNAME:S/qcc//}${PORTVERSION:S/.//g}src

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Advanced QuakeC compiler/decompiler

LICENSE=	GPLv2

USES=		zip

MAKEFILE=	${FILESDIR}/Makefile

PLIST_FILES=	bin/frikqcc bin/frikqcdec

NO_STAGE=	yes
do-install:
.for p in ${PLIST_FILES:T}
	${INSTALL_PROGRAM} ${WRKSRC}/${p} ${PREFIX}/bin
.endfor

.include "${.CURDIR}/../quake-source/Makefile.include"
.include <bsd.port.mk>
