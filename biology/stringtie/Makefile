# $FreeBSD$

PORTNAME=	stringtie
DISTVERSION=	1.3.4d
CATEGORIES=	biology
MASTER_SITES=	http://ccb.jhu.edu/software/stringtie/dl/

MAINTAINER=	mzaki@niid.go.jp
COMMENT=	Transcript assembly and quantification for RNA-seq

LICENSE=	ART20 MIT
LICENSE_COMB=	multi
LICENSE_FILE_ART20=	${WRKSRC}/LICENSE
LICENSE_FILE_MIT=	${WRKSRC}/samtools-0.1.18/COPYING

USES=		gmake
ALL_TARGET=	release

PLIST_FILES=	bin/stringtie

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/stringtie ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
