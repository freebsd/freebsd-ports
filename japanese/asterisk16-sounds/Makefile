# New ports collection makefile for:	ja-asterisk16-sounds
# Date created:		2010-06-12
# Whom:			TAKAHASHI Kaoru <kaoru@kaisei.org>
#
# $FreeBSD$
#

PORTNAME=	asterisk16
PORTVERSION=	1.6
CATEGORIES=	japanese net
MASTER_SITES=	http://ftp.voip-info.jp/asterisk/sounds/${PORTVERSION:S|.|_|}/ \
	ftp://ftp.voip-info.jp/asterisk/sounds/${PORTVERSION:S|.|_|}/
PKGNAMESUFFIX=	-sounds
DISTNAME=	asterisk-sound-jp_${PORTVERSION:S|.||}_pre

MAINTAINER=	kaoru@kaisei.org
COMMENT=	Japanese sound files for Asterisk 1.6

RUN_DEPENDS=	asterisk:${PORTSDIR}/net/asterisk16

NO_BUILD=	yes
ASTERISKDIR=	${PREFIX}/share/asterisk/sounds
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}
SUB_FILES=	pkg-message
SUB_LIST=	PORTSDIR=${PORTSDIR}

do-install:
	@-${MKDIR} ${ASTERISKDIR}/ja
	for gsm in ${WRKDIR}/ja/*.gsm; do \
		${INSTALL_DATA} "$$gsm" ${ASTERISKDIR}/ja ; \
	done
	@${MKDIR} ${ASTERISKDIR}/ja/digits
	for digitgsm in ${WRKDIR}/ja/digits/*.gsm; do \
		${INSTALL_DATA} "$$digitgsm" ${ASTERISKDIR}/ja/digits ; \
	done
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/ja
	@cd ${WRKDIR}/ja && ${INSTALL_DATA} README.txt ${DOCSDIR}/ja
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
