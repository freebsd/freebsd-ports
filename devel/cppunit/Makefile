# New ports collection makefile for:	cppunit
# Date created:				14 Feb 2002
# Whom:					Graeme Cross <gcross@netspace.net.au>
#
# $FreeBSD$

PORTNAME=	cppunit
PORTVERSION=	1.12.1
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	yzlin@FreeBSD.org
COMMENT=	C++ port of the JUnit framework for unit testing

USE_AUTOTOOLS=	libtool:22
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

.if defined(WITH_DOXYGEN)
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen
CONFIGURE_ARGS+=	--enable-doc --enable-doxygen --enable-html-docs
PLIST_SUB+=	HTMLDOCS="" PORTDOCS=""
.else
CONFIGURE_ARGS+=	--disable-doc --disable-doxygen
PLIST_SUB+=	HTMLDOCS="@comment "
.endif

MAN1=		cppunit-config.1
#MANCOMPRESSED=	no

pre-everything::
.if !defined(WITH_DOXYGEN)
	@${ECHO_MSG}
	@${ECHO_MSG} "You could define WITH_DOXYGEN if you want HTML documentation"
	@${ECHO_MSG}
.endif

post-patch:
	@${REINPLACE_CMD} -Ee "s,^(pkgconfigdatadir).*,\1 = $$\(prefix\)/libdata/pkgconfig," \
		${WRKSRC}/Makefile.in

post-install:
	@${FIND} ${PREFIX}/include/cppunit ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${PREFIX}/include/cppunit -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
.if !defined(NOPORTDOCS) || defined(WITH_DOXYGEN)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/FAQ ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/NEWS ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
