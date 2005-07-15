# New ports collection makefile for:	irssi-scripts
# Date created:				Jul 14 2005
# Whom:					Alexey Mikhailov <karma@ez.pereslavl.ru>
#
# $FreeBSD$
#

PORTNAME=	irssi-scripts
PORTVERSION=	20050609
CATEGORIES=	irc
MASTER_SITES=	http://ftp.debian.org/debian/pool/main/i/${PORTNAME}/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	karma@ez.pereslavl.ru
COMMENT=	Collection of useful scripts for the irssi IRC-client

RUN_DEPENDS=	irssi:${PORTSDIR}/irc/irssi

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

NO_BUILD=	yes

do-install:
	cd ${WRKSRC} &&	tar xzf scripts.tar.gz && cd scripts && \
	${FIND} . | ${CPIO} --quiet -pdm -L -R ${LIBOWN}:${LIBGRP} \
	${PREFIX}/share/irssi/scripts

.include <bsd.port.mk>
