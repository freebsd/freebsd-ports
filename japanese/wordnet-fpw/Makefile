# New ports collection makefile for:	WordNet - JIS X 4081 format version
# Date created:        	00/06/19
# Whom:			Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wordnet-fpw
PORTVERSION=	${WN_VER}.${WNFPW_VER}
CATEGORIES=	japanese
MASTER_SITES=	http://openlab.ring.gr.jp/edict/fpw/dist/wordnet/ \
		ftp://ftp.dict.org/pub/dict/pre/
DISTNAME=	wordnet-${WN_VER}-fpw${WNFPW_VER}-src
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		dict-wn-${WN_ORG_VER}-pre.tar.gz
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	taoka@FreeBSD.org

BUILD_DEPENDS=	fpwmake:${PORTSDIR}/japanese/freepwing \
		catdump:${PORTSDIR}/japanese/epwutil \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Jcode.pm:${PORTSDIR}/japanese/p5-Jcode

WRKSRC=		${WRKDIR}/wordnet-${WN_VER}-fpw${WNFPW_VER}
WNFPW_VER=	1.1.2
WN_VER=		1.6
WN_ORG_VER=	1.5

post-extract:
	cd ${WRKSRC}; \
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
		${_DISTDIR}/dict-wn-${WN_ORG_VER}-pre.tar.gz \
		${EXTRACT_AFTER_ARGS}; \
	${GZIP_CMD} ${EXTRACT_BEFORE_ARGS} wn.dict.dz > wn.dict

do-build:
		cd ${WRKSRC}; \
		fpwmake > /dev/null; \
		fpwmake catalogs

do-install:
	${MKDIR} ${PREFIX}/share/dict/wordnet-fpw/wordnet/data
	${INSTALL_DATA} ${WRKSRC}/honmon ${PREFIX}/share/dict/wordnet-fpw/wordnet/data
	${INSTALL_DATA} ${WRKSRC}/catalogs ${PREFIX}/share/dict/wordnet-fpw
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/wordnet-fpw
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/wordnet-fpw
.endif

.include <bsd.port.mk>
