# New ports collection makefile for:	Munhwa fonts collection(cid)
# Date created:		30 Jun 1999
# Whom:			CHOI Junho <cjh@kr.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	munhwafonts-cid
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	korean print
MASTER_SITES=	ftp://ftp.ora.com/pub/examples/nutshell/cjkv/adobe/ \
		ftp://ftp.ora.com/pub/examples/nutshell/cjkv/adobe/samples/
DISTNAME=	${PORTNAME}
DISTFILES=	${CID_FONTS_KO} ${CID_CMAP_KO}
EXTRACT_ONLY=	${CID_CMAP_KO}

MAINTAINER=	cjh@FreeBSD.org
COMMENT=	Munhwa CID fonts collection(Basic set)

# sample fonts(cid, free Korean fonts is just only one.. :< )
CID_FONTS_KO=   Munhwa-Regular Munhwa-Bold \
		MunhwaGothic-Regular MunhwaGothic-Bold
# CID CMAP
CID_CMAP_KO=    ak12.tar.Z

NO_BUILD=	YES

do-install:
	${MKDIR} ${PREFIX}/share/ghostscript/fonts
	${MKDIR} ${PREFIX}/share/ghostscript/fonts/CMap
	${INSTALL_DATA} ${FILESDIR}/Munhwa-Regular-KSC-EUC-H.gsf \
			${FILESDIR}/MunhwaGothic-Regular-KSC-EUC-H.gsf \
			${FILESDIR}/Munhwa-Bold-KSC-EUC-H.gsf \
			${FILESDIR}/MunhwaGothic-Bold-KSC-EUC-H.gsf \
			${PREFIX}/share/ghostscript/fonts
	for file in ${CID_FONTS_KO}; do \
		${INSTALL_DATA} ${DISTDIR}/$$file \
			${PREFIX}/share/ghostscript/fonts; \
	done
	${INSTALL_DATA} ${WRKDIR}/ak12/CMap/* \
			${PREFIX}/share/ghostscript/fonts/CMap

.include <bsd.port.mk>
