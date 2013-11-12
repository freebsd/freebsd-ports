# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	umark
DISTVERSION=	2.0.0-Beta3
PORTREVISION=	7
CATEGORIES=	games benchmarks
MASTER_SITES=	SF/ut2k3botbench/UMark%20for%20Linux/2.0.0%20Beta%203
DISTNAME=	UMark-for-Linux-v${DISTVERSION:S/.//g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Unreal Tournament 200x series benchmark utility

LICENSE=	GPLv2

USES=		pkgconfig
USE_GNOME=	gtk20
WRKSRC=		${WRKDIR}/UMark/src
MAKEFILE=	${FILESDIR}/Makefile
SUB_FILES=	pkg-message
PORTDOCS=	ChangeLog INSTALL README TODO

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/UMark/install_umark_data.sh ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/UMark/utxinfo.pl ${STAGEDIR}${DATADIR}
	cd ${WRKDIR}/UMark && ${FIND} data html pixmaps | \
		${CPIO} -pdu ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKDIR}/UMark/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
