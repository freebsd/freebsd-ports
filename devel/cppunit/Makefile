# New ports collection makefile for:	cppunit
# Date created:				14 Feb 2002
# Whom:					Graeme Cross <gcross@netspace.net.au>
#
# $FreeBSD$

PORTNAME=	cppunit
PORTVERSION=	1.8.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

.if defined(WITH_DOXYGEN)
BUILD_DEPENDS=	doxygen:${PORTSDIR}/devel/doxygen
.endif

MAINTAINER=	gcross@fastmail.fm
COMMENT=	C++ port of the JUnit framework for unit testing

HAS_CONFIGURE=	yes
.if defined(WITH_DOXYGEN) && !defined(NOPORTDOCS)
CONFIGURE_ARGS+= --enable-doc --enable-doxygen --enable-html-docs
PLIST_SUB+=	DOXYGEN=""
.else
CONFIGURE_ARGS+= --disable-doc --disable-doxygen
PLIST_SUB+=	DOXYGEN="@comment "
.endif
INSTALLS_SHLIB=	yes
.if !defined(NOMAN)
MAN1=		cppunit-config.1
.endif
MANCOMPRESSED=	no

pre-everything::
.if !defined(WITH_DOXYGEN) && !defined(NOPORTDOCS)
	@${ECHO_MSG}
	@${ECHO_MSG} You could define WITH_DOXYGEN if you want HTML documentation
	@${ECHO_MSG}
.endif

post-install:
.if !defined(NOPORTDOCS)
.if !defined(WITH_DOXYGEN)
	${MKDIR} -p ${PREFIX}/share/doc/cppunit
	${INSTALL_MAN} ${WRKSRC}/doc/FAQ ${PREFIX}/share/doc/cppunit
.endif	
	${INSTALL_MAN} ${WRKSRC}/NEWS ${PREFIX}/share/doc/cppunit  
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/cppunit
.endif
	
.include <bsd.port.mk>
