# New ports collection makefile for:	wdic - JIS X 4081 format version
# Date created:        	2000.07.12
# Whom:			Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wdic-fpw
PORTVERSION=	${SCRPT_VERSION}
CATEGORIES=	japanese
MASTER_SITES=	http://www.infonets.hiroshima-u.ac.jp/~taoka/FreeBSD/ports/ \
		http://www.wdic.org/file/ \
		http://openlab.ring.gr.jp/edict/fpw/dist/wdic/
DISTNAME=	${PORTNAME}${PORTVERSION}-src
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DICTFILES}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=    	taoka@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/share/doc/freepwing/fpwutils.mk:${PORTSDIR}/japanese/freepwing \
		catdump:${PORTSDIR}/japanese/epwutil \
		lha:${PORTSDIR}/archivers/lha \
		nkf:${PORTSDIR}/japanese/nkf \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Jcode.pm:${PORTSDIR}/japanese/p5-Jcode
#		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/NKF.pm:${PORTSDIR}/japanese/p5-nkf

USE_GMAKE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION}
DICT_VERSION=	002
SCRPT_VERSION=	1.1b
DICTFILES=	wdc${DICT_VERSION}.lzh wdc00p12.lzh

post-extract:
	${MKDIR} ${WRKSRC}/wdic${DICT_VERSION}
	${CP} ${LOCALBASE}/share/doc/freepwing/fpwutils.mk ${WRKSRC}
	cd ${WRKSRC}/wdic${DICT_VERSION}; \
	for i in ${DICTFILES}; do \
		lha xqf ${DISTDIR}/$$i; \
	done

post-build:
	cd ${WRKSRC}; nkf -eSd catalogs.sjis > catalogs.txt; \
	catdump -u catalogs.txt catalogs

do-install:
	${MKDIR} ${PREFIX}/share/dict/wdic-fpw/wdic/data
	${MKDIR} ${PREFIX}/share/dict/wdic-fpw/wdic/gaiji
	${INSTALL_DATA} ${WRKSRC}/honmon ${PREFIX}/share/dict/wdic-fpw/wdic/data
	${INSTALL_DATA} ${WRKSRC}/catalogs ${PREFIX}/share/dict/wdic-fpw
	${INSTALL_DATA} ${WRKSRC}/gai16h ${PREFIX}/share/dict/wdic-fpw/wdic/gaiji
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/wdic-fpw
	${INSTALL_DATA} ${WRKSRC}/readme.1st ${PREFIX}/share/doc/wdic-fpw
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${PREFIX}/share/doc/wdic-fpw
.endif


.include <bsd.port.mk>
