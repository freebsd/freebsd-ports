# New ports collection makefile for:	omniBroker
# Date created:		17 May 1997
# Whom:			ejc@bazzle.com
# Version required:	1.0
#
# $Id: Makefile,v 1.4 1997/11/26 23:58:54 jseger Exp $
#

DISTNAME=	OB-1.0
PKGNAME=	omniBroker-1.0
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.ooc.com/pub/OmniBroker/1.0/

MAINTAINER=	ejc@bazzle.com

BROKEN=		awaiting upgrade to ORBacus -- see PR ports/7034

HAS_CONFIGURE=	yes
CONFIGURE_ENV=	CXX=c++ CXXFLAGS="--no-implicit-templates -fhandle-exceptions -Wall"
MAN1=		idl.1

post-install:
	${LDCONFIG} -m $(PREFIX)/lib
	${MKDIR} ${PREFIX}/share/doc/omniBroker
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${PREFIX}/share/doc/omniBroker

.include <bsd.port.mk>
