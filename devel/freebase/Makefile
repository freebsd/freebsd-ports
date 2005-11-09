# New ports collection makefile for:	FreeBASE
# Date created:		16 June 2004
# Whom:			Alexander Novitsky <alecn2002@yandex.ru>
#
# $FreeBSD$
#

PORTNAME=	freebase
PORTREVISION=	1

COMMENT=	Plugin subsystem of FreeRIDE

WRKSRC=		${WRKDIR}/${DISTNAME}/${PORTNAME}

MASTERDIR=	${.CURDIR}/../freeride
FILESDIR=	${.CURDIR}/files
PATCHDIR=	${FILESDIR}
PLIST=	${.CURDIR}/pkg-plist

do-install:
	cd ${WRKSRC}; ${RUBY} bin/install.rb --prefix=${PREFIX}

.include "${MASTERDIR}/Makefile"
