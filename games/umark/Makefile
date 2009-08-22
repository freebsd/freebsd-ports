# New ports collection makefile for:	UMark
# Date created:				31 Jul 2005
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	umark
DISTVERSION=	2.0.0-Beta3
PORTREVISION=	4
CATEGORIES=	games benchmarks
MASTER_SITES=	SF/ut2k3botbench/UMark%20for%20Linux/2.0.0%20Beta%203
DISTNAME=	UMark-for-Linux-v${DISTVERSION:S/.//g}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Unreal Tournament 200x series benchmark utility

USE_GNOME=	gtk20
WRKSRC=		${WRKDIR}/UMark/src
MAKEFILE=	${FILESDIR}/Makefile
SUB_FILES+=	pkg-message
PORTDOCS=	*

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/UMark/install_umark_data.sh ${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/UMark/utxinfo.pl ${DATADIR}
	cd ${WRKDIR}/UMark && ${FIND} data html pixmaps | \
		${CPIO} -pdu -R ${SHAREOWN}:${SHAREGRP} ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
. for txt in ChangeLog INSTALL README TODO
	${INSTALL_DATA} ${WRKDIR}/UMark/${txt} ${DOCSDIR}
. endfor
.endif

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
