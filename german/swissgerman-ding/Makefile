# New ports collection makefile for:	swissgerman-ding
# Date created:				15 Jul 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	swissgerman-ding
PORTVERSION=	1.4
PORTREVISION=	2
CATEGORIES=	german
MASTER_SITES=	# none
PKGNAMEPREFIX=	de-
DISTFILES=	# none

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	A swiss high german german doppel-s free language pack for de-ding

RUN_DEPENDS=	${DICTFILE}:${PORTSDIR}/german/ding
BUILD_DEPENDS=	${RUN_DEPENDS}

NO_WRKSUBDIR=	yes
USE_PERL5=	yes

DICTFILE=	${PREFIX}/share/ding/de-en.txt
SWISSDICT=	de_ch-en.txt

PLIST_FILES=	share/ding/de_ch-en.txt

do-fetch:
	@${DO_NADA}

do-build:
	@${CP} ${DICTFILE} ${WRKDIR}/${SWISSDICT}
	${PERL5} -pi.orig -e '$${sz}="\x{009F}"; s/Ã$${sz}/ss/g' \
		${WRKDIR}/${SWISSDICT}

do-install:
	${INSTALL_DATA} ${WRKDIR}/${SWISSDICT} ${PREFIX}/share/ding

post-install:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You can now configure ${SWISSDICT} in your 'Settings' menu."
	@${ECHO_MSG} ""

.include <bsd.port.mk>
