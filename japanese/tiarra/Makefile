# New ports collection makefile for:	tiarra
# Date Created:		Jul 27 2006
# Whom:			Hajimu UMEMOTO <ume@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tiarra
PORTVERSION=	20100212
#PORTREVISION=	0
CATEGORIES=	japanese irc ipv6
MASTER_SITES=	http://www.clovery.jp/tiarra/archive/2010/02/

MAINTAINER=	ume@FreeBSD.org
COMMENT=	IRC Proxy software

RUN_DEPENDS=	${SITE_PERL}/IO/Socket/INET6.pm:${PORTSDIR}/net/p5-IO-INET6

USE_PERL5_RUN=	yes
USE_BZIP2=	yes
USE_RC_SUBR=	tiarra
NO_BUILD=	yes

SUB_FILES=	pkg-install pkg-deinstall pkg-message
SUB_LIST=	TIARRA_USER=${TIARRA_USER} \
		TIARRA_GROUP=${TIARRA_GROUP}

PLIST_SUB=	TIARRA_USER=${TIARRA_USER} \
		TIARRA_GROUP=${TIARRA_GROUP}

TIARRA_USER=	tiarra
TIARRA_GROUP=	tiarra

do-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
	@${MKDIR} ${PREFIX}/tiarra
	@${TAR} cfC - ${WRKSRC} . | ${TAR} xfC - ${PREFIX}/tiarra
	@if [ ! -f ${PREFIX}/tiarra/tiarra.conf ]; then \
		${CP} -p ${PREFIX}/tiarra/sample.conf \
			${PREFIX}/tiarra/tiarra.conf; \
	fi
	@${CHOWN} -R ${BINOWN}:${BINGRP} ${PREFIX}/tiarra
	@${MKDIR} ${PREFIX}/tiarra/log
	@${CHOWN} -R ${TIARRA_USER}:${TIARRA_GROUP} ${PREFIX}/tiarra/log
	@${CHMOD} o-rwx ${PREFIX}/tiarra/log
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
