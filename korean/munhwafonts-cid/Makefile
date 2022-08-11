PORTNAME=	munhwafonts-cid
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	korean print
MASTER_SITES=	ftp://ftp.ora.com/pub/examples/nutshell/cjkv/adobe/samples/
DISTNAME=	${PORTNAME}
DISTFILES=	${CID_FONTS_KO}
EXTRACT_ONLY=	# empty

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Munhwa CID fonts collection(Basic set)

# sample fonts(cid, free Korean fonts is just only one.. :< )
CID_FONTS_KO=	Munhwa-Regular Munhwa-Bold \
		MunhwaGothic-Regular MunhwaGothic-Bold
FONTSDIR=	share/fonts/CIDFont

NO_BUILD=	YES
PLIST_SUB=	FONTSDIR=${FONTSDIR}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${FONTSDIR}
	${INSTALL_DATA} ${FILESDIR}/Munhwa-Regular-KSC-EUC-H.gsf \
			${FILESDIR}/MunhwaGothic-Regular-KSC-EUC-H.gsf \
			${FILESDIR}/Munhwa-Bold-KSC-EUC-H.gsf \
			${FILESDIR}/MunhwaGothic-Bold-KSC-EUC-H.gsf \
			${STAGEDIR}${PREFIX}/${FONTSDIR}
	for file in ${CID_FONTS_KO}; do \
		${INSTALL_DATA} ${DISTDIR}/$$file \
			${STAGEDIR}${PREFIX}/${FONTSDIR}; \
	done

.include <bsd.port.mk>
