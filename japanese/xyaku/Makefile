# New ports collection makefile for:	xyaku
# Date created:		7 Dec 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	xyaku
PORTVERSION=	1.4.0
PORTREVISION=	1
CATEGORIES=	japanese textproc
MASTER_SITES=	http://home.catv.ne.jp/pp/ginoue/software/xyaku/

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A general dictionary/search engine front-end for X

RUN_DEPENDS=	${EDICT_FILE}:${PORTSDIR}/japanese/edict \
		${RUBY_SITEARCHLIBDIR}/eb.so:${PORTSDIR}/japanese/ruby-eb

USE_X_PREFIX=	yes
USE_RUBY=	yes

USE_AUTOCONF=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--with-edict="${EDICT_FILE}" \
		--with-ruby="${RUBY}" \
		--with-netscape="${LOCALBASE}/bin/netscape"

EDICT_FILE=	${LOCALBASE}/share/dict/edict/edict
DOCS_EN=	AUTHORS ChangeLog INSTALL NEWS README TODO \
		addin/ADDIN.ChangeLog addin/ADDIN.txt
DOCS_JA=	addin/README.searcheb.ja

post-extract:
	${MV} ${WRKSRC}/addin/ChangeLog ${WRKSRC}/addin/ADDIN.ChangeLog

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/xyaku/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/xyaku/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/xyaku/ja/
.endfor
.endif

.include <bsd.port.mk>
