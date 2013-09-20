# Created by: Romain Tartiere <romain@blogreen.org>
# $FreeBSD$

PORTNAME=	tomboy-plugin-wordcount
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	http://www.proven-corporation.com/~jhs/
DISTNAME=	tomboy-wordcount-${PORTVERSION}

MAINTAINER=	mono@FreeBSD.org
COMMENT=	Counts lines, words, and characters in your notes

BUILD_DEPENDS=	tomboy:${PORTSDIR}/deskutils/tomboy
RUN_DEPENDS=	tomboy:${PORTSDIR}/deskutils/tomboy

ALL_TARGET=	Wordcount.dll

PLIST_FILES=	lib/tomboy/addins/Wordcount.dll

NO_STAGE=	yes
do-install:
	cd ${WRKSRC} && ${INSTALL_DATA} Wordcount.dll ${PREFIX}/lib/tomboy/addins/

.include <bsd.port.mk>
