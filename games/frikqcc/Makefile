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

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/frikqcc ${WRKSRC}/frikqcdec \
		${STAGEDIR}${PREFIX}/bin

.include "${.CURDIR}/../quake-source/Makefile.include"
.include <bsd.port.mk>
