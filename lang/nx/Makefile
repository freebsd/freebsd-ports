PORTNAME=	nx
DISTVERSION=	2.4.0
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	SF/next-scripting/${DISTVERSION}/
DISTNAME=	nsf${DISTVERSION}

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	Highly flexible, Tcl-based, object-oriented scripting language
WWW=		https://next-scripting.org

LICENSE=	MIT

OPTIONS_DEFINE=	DOCS

USES+=		gmake tcl:tea
USE_LDCONFIG=	yes

GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

TEST_TARGET=	test
PLIST_SUB+=	PKGNAME=${DISTNAME} PORTVERSION=${PORTVERSION}
PORTDOCS=	*

post-patch:
	cd ${WRKSRC}/doc && for f in *.1; do ${MV} $$f $${f%.1}.nx.1; done
	cd ${WRKSRC}/doc && for f in *.3; do ${MV} $$f $${f%.3}.nx.3; done

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${DISTNAME}/lib${DISTNAME}.so

.include <bsd.port.mk>
