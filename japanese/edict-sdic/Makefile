# New ports collection makefile for:	EDICT - SDICT format version
# Date created:        	00/01/14
# Whom:			Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	edict-sdic
PORTVERSION=	20010615
CATEGORIES=	japanese
MASTER_SITES=	ftp://pine.kuee.kyoto-u.ac.jp/pub/tsuchiya/sdic/ \
		ftp://ftp.cc.monash.edu.au/pub/nihongo/ \
		ftp://ftp.cdrom.com/pub/japanese/monash/ \
		ftp://ftp.sedl.org/pub/mirrors/nihongo/ \
		ftp://ftp.u-aizu.ac.jp/pub/SciEng/nihongo/ftp.cc.monash.edu.au/
DISTNAME=	sdic-2.1.2
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		edict.gz \
		edict_doc.txt
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	taoka@FreeBSD.org

ALL_TARGET=	jedict.sdic eedict.sdic
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-emacs=mule \
		--with-lispdir=${PREFIX}/share/emacs/site-lisp \
		--with-dictdir=${PREFIX}/share/dict
USE_PERL5=	yes

post-extract:
	${CP} -f ${DISTDIR}/edict.gz ${WRKSRC}
	${CP} -f ${DISTDIR}/edict_doc.txt ${WRKSRC}
	${GZIP_CMD} -d ${WRKSRC}/edict.gz

do-install:
	${MKDIR} ${PREFIX}/share/dict
	${INSTALL_DATA} ${WRKSRC}/*.sdic ${PREFIX}/share/dict
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/edict
	${INSTALL_DATA} ${WRKSRC}/edict_doc.txt ${PREFIX}/share/doc/edict
.endif

.include <bsd.port.mk>
