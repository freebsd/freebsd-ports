# Created by: Graeme Cross <gcross@netspace.net.au>
# $FreeBSD$

PORTNAME=	cppunit
PORTVERSION=	1.12.1
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	bdrewery@FreeBSD.org
COMMENT=	C++ port of the JUnit framework for unit testing

OPTIONS_DEFINE=	DOXYGEN

USES=		libtool pathfix
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOXYGEN}
BUILD_DEPENDS+=		doxygen:${PORTSDIR}/devel/doxygen \
			dot:${PORTSDIR}/graphics/graphviz
CONFIGURE_ARGS+=	--enable-doc --enable-doxygen --enable-html-docs
PLIST_SUB+=		PORTDOCS=""
.else
CONFIGURE_ARGS+=	--disable-doc --disable-doxygen --disable-html-docs
PLIST_SUB+=		PORTDOCS="@comment "
.endif

post-install:
	${FIND} ${STAGEDIR}${PREFIX}/include/cppunit ! -type d | \
		${SED} 's,^${STAGEDIR}${PREFIX}/,,' >> ${TMPPLIST}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${FIND} ${WRKSRC}/doc/html -not -type d \
                | ${SED} 's,^${WRKSRC}/doc/html,${DOCSDIR_REL},' >> ${TMPPLIST}
	${FIND} ${STAGEDIR}${PREFIX}/include/cppunit -type d | ${SORT} -r | \
		${SED} 's,^${STAGEDIR}${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
	${INSTALL_MAN} ${WRKSRC}/doc/FAQ ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/NEWS ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
