# New ports collection makefile for:	Munhwa fonts collection(cid)
# Version required:     none
# Date created:		30 Jun 1999
# Whom:			CHOI Junho <cjh@kr.freebsd.org>
#
# $FreeBSD$
#

DISTNAME=	munhwafonts-cid
PKGNAME=	ko-munhwafonts-cid-1.0
CATEGORIES=	korean print
MASTER_SITES=	ftp://ftp.ora.com/pub/examples/nutshell/cjkv/adobe/ \
		ftp://ftp.ora.com/pub/examples/nutshell/cjkv/adobe/samples/
DISTFILES=	${CID_FONTS_KO} ${CID_CMAP_KO}

MAINTAINER=	cjh@kr.freebsd.org

BUILD_DEPENDS=	${PREFIX}/share/ghostscript/fonts/Fontmap:${PORTSDIR}/print/gsfonts

# sample fonts(cid, free Korean fonts is just only one.. :< )
CID_FONTS_KO=   Munhwa-Regular MunhwaGothic-Regular
# CID CMAP
CID_CMAP_KO=    ak11.tar.Z

NO_BUILD=	YES

do-extract:
	${MKDIR} ${WRKDIR}
	cd ${WRKDIR} && tar -xzf ${DISTDIR}/${CID_CMAP_KO}

do-install:
	${INSTALL_DATA} ${FILESDIR}/Munhwa-Regular-KSC-EUC-H.gsf \
			${FILESDIR}/MunhwaGothic-Regular-KSC-EUC-H.gsf \
			${PREFIX}/share/ghostscript/fonts
	for file in ${CID_FONTS_KO}; do \
		${INSTALL_DATA} ${DISTDIR}/$$file \
			${PREFIX}/share/ghostscript/fonts; \
	done
	${MKDIR} ${PREFIX}/share/ghostscript/fonts/CMap; &&\
	${INSTALL_DATA} ${WRKDIR}/ak11/CMap/* \
			${PREFIX}/share/ghostscript/fonts/CMap

.include <bsd.port.mk>
