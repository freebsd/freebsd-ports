# New ports collection makefile for:	EDICT - JIS X 4081 format version
# Version required:	1.1
# Date created:        	00/01/14
# Whom:			Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	edict-fpw1.1-src
PKGNAME=	ja-edict-fpw-1.1
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/misc/freepwing/fpwbooks/edict/ \
		ftp://ftp.cc.monash.edu.au/pub/nihongo/ \
		ftp://ftp.cdrom.com/pub/japanese/monash/ \
		ftp://ftp.sedl.org/pub/mirrors/nihongo/ \
		ftp://ftp.u-aizu.ac.jp/pub/SciEng/nihongo/ftp.cc.monash.edu.au/
DISTFILES=	edict-fpw1.1-src.tar.gz edict.gz edict.doc

MAINTAINER=    	taoka@FreeBSD.org

BUILD_DEPENDS=	fpwmake:${PORTSDIR}/japanese/freepwing \
		catdump:${PORTSDIR}/japanese/epwutil

WRKSRC=		${WRKDIR}/edict-fpw1.1
EXTRACT_ONLY=	edict-fpw1.1-src.tar.gz

post-extract:
	${MKDIR} ${WRKSRC}/source
	${CP} -f ${DISTDIR}/edict.gz ${WRKSRC}/source
	${CP} -f ${DISTDIR}/edict.doc ${WRKSRC}/source
	${GZIP_CMD} -d ${WRKSRC}/source/edict.gz

do-build:
		cd ${WRKSRC}; fpwmake > /dev/null; \
		fpwmake catalogs

do-install:
	${MKDIR} ${PREFIX}/share/dict/edict-fpw/edict/data
	${INSTALL_DATA} ${WRKSRC}/honmon ${PREFIX}/share/dict/edict-fpw/edict/data
	${INSTALL_DATA} ${WRKSRC}/catalogs ${PREFIX}/share/dict/edict-fpw
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/edict-fpw
	${INSTALL_DATA} ${WRKSRC}/source/edict.doc ${PREFIX}/share/doc/edict-fpw
	${INSTALL_DATA} ${WRKSRC}/README.pkg ${PREFIX}/share/doc/edict-fpw
.endif

.include <bsd.port.mk>
