# New ports collection makefile for:	wdic - JIS X 4081 format version
# Date created:        	2000.07.12
# Whom:			Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wdic001-fpw
PORTVERSION=	0.11
CATEGORIES=	japanese
MASTER_SITES=	http://www.wdic.org/file/ \
		http://www.geocities.co.jp/SiliconValley-Bay/2872/
DISTFILES=	${DICTFILES} wdc001fpw-${PORTVERSION}.tar.gz
EXTRACT_ONLY=	wdc001fpw-${PORTVERSION}.tar.gz

MAINTAINER=    	taoka@FreeBSD.org

BUILD_DEPENDS=	nkf:${PORTSDIR}/japanese/nkf \
		fpwmake:${PORTSDIR}/japanese/freepwing \
		catdump:${PORTSDIR}/japanese/epwutil \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Jcode.pm:${PORTSDIR}/japanese/p5-Jcode \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/NKF.pm:${PORTSDIR}/japanese/p5-nkf

WRKSRC=		${WRKDIR}/wdc001-fpw${PORTVERSION}
DICTFILES=	wdc001a.lzh wdc001b.lzh wdc001c.lzh wdc001d.lzh wdc001e.lzh \
		wdc001f.lzh
ALL_TARGET=	#

post-extract:
	cd ${WRKSRC}/data; \
	for i in ${DICTFILES}; do \
		lha xqf ${DISTDIR}/$$i; \
	done
# join several dictionaris
	${CAT} ${FILESDIR}/MOE_RAIL.H ${WRKSRC}/data/MOE[12].DIC ${WRKSRC}/data/RAIL.DIC > ${WRKSRC}/data/MOE_RAIL.DIC
	${RM} ${WRKSRC}/data/MOE[12].DIC  ${WRKSRC}/data/RAIL.DIC
	${CAT} ${FILESDIR}/YOGOPASO.H ${WRKSRC}/data/YOGO.DIC ${WRKSRC}/data/PASO.DIC > ${WRKSRC}/data/YOGOPASO.DIC
	${RM}  ${WRKSRC}/data/PASO.DIC ${WRKSRC}/data/YOGO.DIC
	${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.org
	${SED} 's,/usr/local/share/eb/data/wdc001,${PREFIX}/share/dict/wdc001-fpw,' \
		${WRKSRC}/Makefile.org > ${WRKSRC}/Makefile

.include <bsd.port.mk>
