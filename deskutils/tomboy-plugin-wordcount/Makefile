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

BROKEN=		Unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2015-11-26
ALL_TARGET=	Wordcount.dll

ADDINS_DIR=	lib/tomboy/addins
PLIST_FILES=${ADDINS_DIR}/Wordcount.dll

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${ADDINS_DIR}
	${INSTALL_DATA} ${WRKSRC}/Wordcount.dll ${STAGEDIR}${PREFIX}/${ADDINS_DIR}

.include <bsd.port.mk>
