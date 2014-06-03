# Created by: TAKAHASHI Kaoru <kaoru@kaisei.org>
# $FreeBSD$

PORTNAME=	asterisk
PORTVERSION=	1.8
CATEGORIES=	japanese net
MASTER_SITES=	http://ftp.voip-info.jp/asterisk/sounds/${VENDORVERSION:S|.|_|}/ \
		ftp://ftp.voip-info.jp/asterisk/sounds/${VENDORVERSION:S|.|_|}/
PKGNAMESUFFIX=	-sounds
DISTNAME=	asterisk-sound-jp_${VENDORVERSION:S|.||}_pre

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Japanese sound files for Asterisk

RUN_DEPENDS=	asterisk:${PORTSDIR}/net/asterisk

VENDORVERSION=	1.6

NO_BUILD=	yes
ASTERISKDIR=	${PREFIX}/share/asterisk/sounds
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}
SUB_FILES=	pkg-message
SUB_LIST=	PORTSDIR=${PORTSDIR}

NO_STAGE=	yes
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
