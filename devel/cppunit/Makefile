# New ports collection makefile for:	cppunit
# Date created:				14 Feb 2002
# Whom:					Graeme Cross <gcross@netspace.net.au>
#
# $FreeBSD$

PORTNAME=	cppunit
PORTVERSION=	1.6.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	gcross@netspace.net.au

HAS_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
.if !defined(NOMAN)
MAN1=		cppunit-config.1
.endif
MANCOMPRESSED=	no

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/cppunit
	${INSTALL_MAN} ${WRKSRC}/NEWS ${PREFIX}/share/doc/cppunit
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/cppunit
	${INSTALL_MAN} ${WRKSRC}/doc/FAQ ${PREFIX}/share/doc/cppunit
	${INSTALL_MAN} ${WRKSRC}/doc/cookbook.html ${PREFIX}/share/doc/cppunit
.endif

.include <bsd.port.mk>
