# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	kyotocabinet
PORTVERSION=	1.2.76
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://fallabs.com/${PORTNAME}/pkg/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Straightforward implementation of DBM

LICENSE=	GPLv3

OPTIONS_DEFINE=	DOCS

CPPFLAGS+=	-fPIC
GNU_CONFIGURE=	yes
MAKE_ARGS=	PCDIR=${PREFIX}/libdata/pkgconfig
REINPLACE_ARGS=	-i ''
USE_LDCONFIG=	yes
USES=		gmake

NOT_FOR_ARCHS=	powerpc
NOT_FOR_ARCHS_REASON=	does not link

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|-lstdc++ ||g' ${WRKSRC}/configure ${WRKSRC}/doc/spex.html ${WRKSRC}/example/Makefile ${WRKSRC}/lab/kcdict/Makefile
.if !${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e '/DOCDIR/d' ${WRKSRC}/Makefile.in
.endif

post-build:
	@cd ${WRKSRC}/ && ${STRIP_CMD} libkyotocabinet.so.16.13.0 kccachetest \
		kcdirmgr kcdirtest kcforestmgr kcforesttest kcgrasstest \
		kchashmgr kchashtest kclangctest kcpolymgr kcpolytest \
		kcprototest kcstashtest kctreemgr kctreetest kcutilmgr \
		kcutiltest

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${FIND} ${STAGEDIR}${DOCSDIR}/ -type d -exec ${CHMOD} 755 '{}' \;
	${FIND} ${STAGEDIR}${DOCSDIR}/ -type f -exec ${CHMOD} 444 '{}' \;
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${DOCSDIR}/
.endif

.include <bsd.port.post.mk>
