# New ports collection makefile for:	The Jargon File - JIS X 4081 format version
# Date created:        	00/06/19
# Whom:			Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jargon-fpw
PORTVERSION=	${JG_VER}.${JGFPW_VER}
CATEGORIES=	japanese
MASTER_SITES=	http://plaza27.mbn.or.jp/~satomii/soft/archive/ \
		http://www.tuxedo.org/~esr/jargon/
DISTNAME=	jarg-fpw${JGFPW_VER}-src
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		jargon-${JG_VER}.tar.gz
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=    	taoka@FreeBSD.org

BUILD_DEPENDS=	fpwmake:${PORTSDIR}/japanese/freepwing \
		catdump:${PORTSDIR}/japanese/epwutil \
		nkf:${PORTSDIR}/japanese/nkf

WRKSRC=		${WRKDIR}/jarg-fpw${JGFPW_VER}
USE_GMAKE=	yes
JGFPW_VER=	1.1
JG_VER=		4.2.0
FJG_VER=	420

post-extract:
	cd ${WRKSRC}; \
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
		${_DISTDIR}/jargon-${JG_VER}.tar.gz \
		${EXTRACT_AFTER_ARGS}
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
		${WRKSRC}/jargon-${JG_VER}/jarg${FJG_VER}.gz \
		> ${WRKSRC}/jarg${FJG_VER}

post-patch:
	${MV} ${WRKSRC}/catalogs.txt ${WRKSRC}/catalogs.txt.org
	nkf -ed ${WRKSRC}/catalogs.txt.org > ${WRKSRC}/catalogs.txt
	${MV} ${WRKSRC}/gaiji/halfchar.txt ${WRKSRC}/gaiji/halfchar.txt.org
	nkf -ed ${WRKSRC}/gaiji/halfchar.txt.org > ${WRKSRC}/gaiji/halfchar.txt

do-build:
	cd ${WRKSRC}; \
	fpwmake -f ${MAKEFILE} > /dev/null; \
	fpwmake -f ${MAKEFILE} catalogs

do-install:
	${MKDIR} ${PREFIX}/share/dict/jargon-fpw/jargon/data
	${INSTALL_DATA} ${WRKSRC}/honmon ${PREFIX}/share/dict/jargon-fpw/jargon/data
	${MKDIR} ${PREFIX}/share/dict/jargon-fpw/jargon/gaiji
	${INSTALL_DATA} ${WRKSRC}/gai16h ${PREFIX}/share/dict/jargon-fpw/jargon/gaiji
	${INSTALL_DATA} ${WRKSRC}/catalogs ${PREFIX}/share/dict/jargon-fpw
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/jargon-fpw
	${INSTALL_DATA} ${WRKSRC}/readme.1st ${PREFIX}/share/doc/jargon-fpw
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${PREFIX}/share/doc/jargon-fpw
.endif

.include <bsd.port.mk>
