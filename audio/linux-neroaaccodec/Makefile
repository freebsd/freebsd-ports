# Created by: Yuichiro AIZAWA <yaizawa@2004.jukuin.keio.ac.jp>
# $FreeBSD: head/audio/linux-neroaaccodec/Makefile 355274 2014-05-26 02:33:38Z eadler $

PORTNAME=	neroaaccodec
PORTVERSION=	1.5.1
CATEGORIES=	audio multimedia linux
MASTER_SITES=	ftp://ftp6.nero.com/tools/
PKGNAMEPREFIX=	linux-
DISTNAME=	NeroAACCodec-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Nero AAC reference quality MPEG-4 and 3GPP audio codec

USES=		dos2unix zip
USE_LINUX=	yes
DOS2UNIX_REGEX=	.*\.txt
ONLY_FOR_ARCHS=	i386 amd64
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
RESTRICTED=	Solely for personal non-commercial and/or technology-evaluation purposes. No reproduction and/or distribution permitted.

PLIST_FILES=	bin/neroAacDec \
		bin/neroAacEnc \
		bin/neroAacTag

PORTDOCS=	NeroAAC_tut.pdf \
	changelog.txt \
	license.txt \
	readme.txt

OPTIONS_DEFINE=	DOCS

do-install:
.for f in ${PLIST_FILES}
	${INSTALL_PROGRAM} ${WRKSRC}/linux/${f:T} ${STAGEDIR}${PREFIX}/bin
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
