# New ports collection makefile for:    Front Line Force Server
# Date created:				Sat Mar 10 16:40:06 EST 2001
# Whom:					pat@databits.net
#
# $FreeBSD$
#

PORTNAME=	flf
PORTVERSION=	1.7b
MASTER_SITES=	http://www.frontlineforce.com/download/ \
		ftp://ftp.clanserver4u.de/exp/hl/mod/flf/

DISTFILES=	frontline17_linux${EXTRACT_SUFX} \
		frontline17b-update${EXTRACT_SUFX}

WRKSRC=		${WRKDIR}/frontline
USE_ZIP=	yes
EXTRACT_BEFORE_ARGS=	-o -qq

COMMENT=	Half-Life mod Frontline Force full server package for Linux

HALFLIFE_COUNTERSTRIKE_MASTER=	${.CURDIR}/../hlserver-cs

.include "${HALFLIFE_COUNTERSTRIKE_MASTER}/Makefile"
