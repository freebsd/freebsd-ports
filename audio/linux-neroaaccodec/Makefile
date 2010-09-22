# New ports collection Makefile for:	linux-nerodigitalaudio
# Date created:				2007-10-27
# Whom:					Yuichiro AIZAWA <yaizawa@2004.jukuin.keio.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	neroaaccodec
PORTVERSION=	1.5.1
CATEGORIES=	audio multimedia linux
MASTER_SITES=	ftp://ftp6.nero.com/tools/
PKGNAMEPREFIX=	linux-
DISTNAME=	NeroAACCodec-${PORTVERSION}

MAINTAINER=	yaizawa@2004.jukuin.keio.ac.jp
COMMENT=	Nero Digital Audio Reference MPEG-4 & 3GPP Audio Encoder

USE_ZIP=	yes
USE_LINUX=	yes
ONLY_FOR_ARCHS=	i386 amd64
NO_BUILD=	yes
WRKSRC=		${WRKDIR}
RESTRICTED=	forbidden by license considerations

PLIST_FILES=	bin/neroAacDec \
		bin/neroAacEnc \
		bin/neroAacTag
.if !defined(NOPORTDOCS)
PLIST_DIRS=	${DOCSDIR_REL}
PLIST_FILES+=	${DOCSDIR_REL}/changelog.txt \
		${DOCSDIR_REL}/license.txt \
		${DOCSDIR_REL}/readme.txt \
		${DOCSDIR_REL}/NeroAAC_tut.pdf
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/linux/neroAacDec ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/linux/neroAacEnc ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/linux/neroAacTag ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/changelog.txt ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/license.txt ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/readme.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/NeroAAC_tut.pdf ${DOCSDIR}
.endif

.include <bsd.port.mk>
