# New ports collection makefile for:	irssi-scripts
# Date created:				Jul 14 2005
# Whom:					Alexey Mikhailov <karma@ez.pereslavl.ru>
#
# $FreeBSD$
#

PORTNAME=	irssi-scripts
PORTVERSION=	20100512
PORTREVISION=	1
CATEGORIES=	irc
MASTER_SITES=	http://ftp.debian.org/debian/pool/main/i/${PORTNAME}/
DISTFILES=	${PORTNAME}_${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	Collection of useful scripts for the irssi IRC-client

RUN_DEPENDS=	irssi:${PORTSDIR}/irc/irssi

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

NO_BUILD=	yes

do-install:
	${MKDIR} ${PREFIX}/share/irssi/scripts
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/*.pl ${PREFIX}/share/irssi/scripts

.include <bsd.port.mk>
