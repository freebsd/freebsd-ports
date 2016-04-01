# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	xyaku
PORTVERSION=	1.4.0
PORTREVISION=	5
CATEGORIES=	japanese textproc
MASTER_SITES=	http://www.sepia.dti.ne.jp/inoue/software/xyaku/ \
		http://redundancy.redundancy.org/mirror/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	General dictionary/search engine front-end for X

LICENSE=	GPLv2

BUILD_DEPENDS=	gawk:lang/gawk
RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/eb.so:japanese/ruby-eb

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-edict="${EDICT_FILE}" \
		--with-ruby="${RUBY}"
USES=		libtool
USE_RUBY=	yes
USE_XORG=	x11 xt xext ice sm

DOCS_EN=	AUTHORS ChangeLog INSTALL NEWS README TODO \
		addin/ADDIN.ChangeLog addin/ADDIN.txt
DOCS_JA=	addin/README.searcheb.ja

OPTIONS_DEFINE=	UTF8
OPTIONS_DEFAULT=	UTF8

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MUTF8}
EDICT_FILE=	${LOCALBASE}/share/dict/edict-utf-8/edict
RUN_DEPENDS+=	${EDICT_FILE}:japanese/edict-utf-8
.else
EDICT_FILE=	${LOCALBASE}/share/dict/edict/edict
RUN_DEPENDS+=	${EDICT_FILE}:japanese/edict
.endif

post-patch:
	@${MV} ${WRKSRC}/addin/ChangeLog ${WRKSRC}/addin/ADDIN.ChangeLog

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/ja
.endfor
.endif

.include <bsd.port.mk>
