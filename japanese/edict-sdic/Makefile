# New ports collection makefile for:	EDICT - SDICT format version
# Version required:	19981007
# Date created:        	00/01/14
# Whom:			Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	edict-19981007
PKGNAME=	ja-edict-sdic-19981007
CATEGORIES=	japanese
MASTER_SITES=	ftp://pine.kuee.kyoto-u.ac.jp/pub/tsuchiya/sdic/ \
		ftp://ftp.cc.monash.edu.au/pub/nihongo/ \
		ftp://ftp.cdrom.com/pub/japanese/monash/ \
		ftp://ftp.sedl.org/pub/mirrors/nihongo/ \
		ftp://ftp.u-aizu.ac.jp/pub/SciEng/nihongo/ftp.cc.monash.edu.au/
DISTFILES=	sdic-2.1.2.tar.gz edict/edict.gz edict/edict.doc

MAINTAINER=    	taoka@FreeBSD.org

WRKSRC=		${WRKDIR}/sdic-2.1.2
EXTRACT_ONLY=	sdic-2.1.2.tar.gz
ALL_TARGET=	jedict.sdic eedict.sdic
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-emacs=mule \
		--with-lispdir=${PREFIX}/share/emacs/site-lisp \
		--with-dictdir=${PREFIX}/share/dict
post-extract:
	${CP} -f ${DISTDIR}/edict/edict.gz ${WRKSRC}
	${CP} -f ${DISTDIR}/edict/edict.doc ${WRKSRC}
	${GZIP_CMD} -d ${WRKSRC}/edict.gz

do-install:
	${MKDIR} ${PREFIX}/share/dict
	${INSTALL_DATA} ${WRKSRC}/*.sdic ${PREFIX}/share/dict
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/edict
	${INSTALL_DATA} ${WRKSRC}/*.doc ${PREFIX}/share/doc/edict
.endif

.include <bsd.port.mk>
