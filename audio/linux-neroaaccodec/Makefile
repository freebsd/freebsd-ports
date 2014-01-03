# Created by: Yuichiro AIZAWA <yaizawa@2004.jukuin.keio.ac.jp>
# $FreeBSD$

PORTNAME=	neroaaccodec
PORTVERSION=	1.5.1
CATEGORIES=	audio multimedia linux
MASTER_SITES=	ftp://ftp6.nero.com/tools/
PKGNAMEPREFIX=	linux-
DISTNAME=	NeroAACCodec-${PORTVERSION}

MAINTAINER=	yaizawa@2004.jukuin.keio.ac.jp
COMMENT=	Nero AAC reference quality MPEG-4 and 3GPP audio codec

USE_ZIP=	yes
NO_STAGE=	yes
USE_LINUX=	yes
USE_DOS2UNIX=	yes
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

.include <bsd.port.options.mk>

do-install:
.for f in ${PLIST_FILES}
	${INSTALL_PROGRAM} ${WRKSRC}/linux/${f:T} ${PREFIX}/bin
.endfor

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
