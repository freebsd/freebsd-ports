# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	umark
DISTVERSION=	2.0.0-Beta3
PORTREVISION=	8
CATEGORIES=	games benchmarks
MASTER_SITES=	SF/ut2k3botbench/UMark%20for%20Linux/2.0.0%20Beta%203
DISTNAME=	UMark-for-Linux-v${DISTVERSION:S/.//g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Unreal Tournament 200x series benchmark utility

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		pkgconfig shebangfix
SHEBANG_FILES=	install_umark_data.sh utxinfo.pl
USE_GNOME=	gtk20
WRKSRC=		${WRKDIR}/UMark
BUILD_WRKSRC=	${WRKSRC}/src
MAKEFILE=	${FILESDIR}/Makefile
SUB_FILES=	pkg-message
PORTDOCS=	ChangeLog INSTALL README TODO

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/install_umark_data.sh ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/utxinfo.pl ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "data html pixmaps" ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
