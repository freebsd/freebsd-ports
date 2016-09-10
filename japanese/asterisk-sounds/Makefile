# Created by: TAKAHASHI Kaoru <kaoru@kaisei.org>
# $FreeBSD$

PORTNAME=	asterisk
PORTVERSION=	1.6
PORTEPOCH=	1
CATEGORIES=	japanese net
MASTER_SITES=	http://ftp.voip-info.jp/asterisk/sounds/${PORTVERSION:S|.|_|}/ \
		ftp://ftp.voip-info.jp/asterisk/sounds/${PORTVERSION:S|.|_|}/
PKGNAMESUFFIX=	-sounds
DISTNAME=	asterisk-sound-jp_${PORTVERSION:S|.||}_pre

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Japanese sound files for Asterisk

RUN_DEPENDS=	asterisk:net/asterisk11

NO_BUILD=	yes
ASTERISKDIR=	${PREFIX}/share/asterisk/sounds
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}
SUB_FILES=	pkg-message
SUB_LIST=	PORTSDIR=${PORTSDIR}

OPTIONS_DEFINE=	DOCS

do-install:
	@-${MKDIR} ${STAGEDIR}${ASTERISKDIR}/ja
	for gsm in ${WRKDIR}/ja/*.gsm; do \
		${INSTALL_DATA} "$$gsm" ${STAGEDIR}${ASTERISKDIR}/ja ; \
	done
	@${MKDIR} ${STAGEDIR}${ASTERISKDIR}/ja/digits
	for digitgsm in ${WRKDIR}/ja/digits/*.gsm; do \
		${INSTALL_DATA} "$$digitgsm" ${STAGEDIR}${ASTERISKDIR}/ja/digits ; \
	done
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/ja
	@cd ${WRKDIR}/ja && ${INSTALL_DATA} README.txt ${STAGEDIR}${DOCSDIR}/ja

.include <bsd.port.mk>
