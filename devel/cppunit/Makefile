# New ports collection makefile for:	cppunit
# Date created:				14 Feb 2002
# Whom:					Graeme Cross <gcross@netspace.net.au>
#
# $FreeBSD$

PORTNAME=	cppunit
PORTVERSION=	1.10.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	gcross@fastmail.fm
COMMENT=	C++ port of the JUnit framework for unit testing

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

.if defined(WITH_DOXYGEN)
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen
CONFIGURE_ARGS+=	--enable-doc --enable-doxygen --enable-html-docs
PORTDOCS=	*
.else
CONFIGURE_ARGS+=	--disable-doc --disable-doxygen
.endif

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

MAN1=		cppunit-config.1
#MANCOMPRESSED=	no

pre-everything::
.if !defined(WITH_DOXYGEN) && !defined(NOPORTDOCS)
	@${ECHO_MSG}
	@${ECHO_MSG} You could define WITH_DOXYGEN if you want HTML documentation
	@${ECHO_MSG}
.endif

post-install:
	@${FIND} ${PREFIX}/include/cppunit ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${PREFIX}/include/cppunit -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/FAQ ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/NEWS ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${DOCSDIR}
.endif
	
.include <bsd.port.mk>
