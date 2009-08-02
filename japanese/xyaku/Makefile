# New ports collection makefile for:	xyaku
# Date created:		7 Dec 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	xyaku
PORTVERSION=	1.4.0
PORTREVISION=	5
CATEGORIES=	japanese textproc
MASTER_SITES=	http://www.sepia.dti.ne.jp/inoue/software/xyaku/ \
		http://redundancy.redundancy.org/mirror/

MAINTAINER=	lx@FreeBSD.org
COMMENT=	A general dictionary/search engine front-end for X

BUILD_DEPENDS=	gawk:${PORTSDIR}/lang/gawk
RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/eb.so:${PORTSDIR}/japanese/ruby-eb

USE_XORG=	x11 xt xext ice sm

OPTIONS=	UTF8 "Use UTF-8 edict dictionaries" on

.if !defined(WITHOUT_UTF8)
EDICT_FILE=	${LOCALBASE}/share/dict/edict-utf-8/edict
RUN_DEPENDS+=	${EDICT_FILE}:${PORTSDIR}/japanese/edict-utf-8
.else
EDICT_FILE=	${LOCALBASE}/share/dict/edict/edict
RUN_DEPENDS+=	${EDICT_FILE}:${PORTSDIR}/japanese/edict
.endif

USE_RUBY=	yes
USE_AUTOTOOLS=	autoconf:213 libtool:22
CONFIGURE_ARGS=	--with-edict="${EDICT_FILE}" \
		--with-ruby="${RUBY}"

DOCS_EN=	AUTHORS ChangeLog INSTALL NEWS README TODO \
		addin/ADDIN.ChangeLog addin/ADDIN.txt
DOCS_JA=	addin/README.searcheb.ja

post-extract:
	${MV} ${WRKSRC}/addin/ChangeLog ${WRKSRC}/addin/ADDIN.ChangeLog

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${MKDIR} ${DOCSDIR}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/ja
.endfor
.endif

.include <bsd.port.mk>
