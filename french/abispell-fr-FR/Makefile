# New ports collection makefile for:	DirectFB
# Date created:				29 Sept 2002
# Whom:					Devaux Fabien <fab@gcu.info>
#
# $FreeBSD$
#

PORTNAME=       abispell-fr
PORTVERSION=	20020418
PORTREVISION=	1
CATEGORIES=     french
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=     abiword
DISTNAME=	abispell-fr-FR.i386

MAINTAINER=     fab@gcu.info
COMMENT=	French (France) ispell dictionary for AbiWord

BUILD_DEPENDS=	AbiWord-2.0:${PORTSDIR}/editors/AbiWord2

IGNORE=	"Does not work with AbiWord-2.0"

PREFIX=         ${X11BASE}
NO_BUILD=       yes

do-install:
	${INSTALL} -m 444 ${WRKDIR}/usr/share/AbiSuite/dictionary/francais.hash-encoding ${PREFIX}/share/AbiSuite/dictionary/
	${INSTALL} -m 444 ${WRKDIR}/usr/share/AbiSuite/dictionary/francais.hash ${PREFIX}/share/AbiSuite/dictionary/

.include <bsd.port.mk>
