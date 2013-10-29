# Created by: Graeme Cross <gcross@netspace.net.au>
# $FreeBSD$

PORTNAME=	cppunit
PORTVERSION=	1.12.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	bdrewery@FreeBSD.org
COMMENT=	C++ port of the JUnit framework for unit testing

OPTIONS_DEFINE=	DOXYGEN

USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOXYGEN}
BUILD_DEPENDS+=		doxygen:${PORTSDIR}/devel/doxygen
CONFIGURE_ARGS+=	--enable-doc --enable-doxygen --enable-html-docs
PLIST_SUB+=		HTMLDOCS="" PORTDOCS=""
.else
CONFIGURE_ARGS+=	--disable-doc --disable-doxygen
PLIST_SUB+=		HTMLDOCS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -Ee "s,^(pkgconfigdatadir).*,\1 = $$\(prefix\)/libdata/pkgconfig," \
		${WRKSRC}/Makefile.in

post-install:
	@${FIND} ${STAGEDIR}${PREFIX}/include/cppunit ! -type d | \
		${SED} 's,^${STAGEDIR}${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${STAGEDIR}${PREFIX}/include/cppunit -type d | ${SORT} -r | \
		${SED} 's,^${STAGEDIR}${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/FAQ ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/NEWS ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
