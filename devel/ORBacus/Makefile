# New ports collection makefile for:	omniBroker
# Date created:		17 May 1997
# Whom:			ejc@bazzle.com
# Version required:	1.0
#
# $Id: Makefile,v 1.1.1.1 1997/06/04 03:38:53 asami Exp $
#

DISTNAME=	OB-1.0
PKGNAME=	omniBroker-1.0
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.ooc.com/pub/OmniBroker/

MAINTAINER=	ejc@bazzle.com

MAN1=		idl.1
HAS_CONFIGURE=	yes
CONFIGURE_ENV=	CXX=c++ CXXFLAGS="--no-implicit-templates -fhandle-exceptions -Wall"

post-install:
	${LDCONFIG} -m $(PREFIX)/lib
	${MKDIR} ${PREFIX}/share/doc/omniBroker
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${PREFIX}/share/doc/omniBroker

.include <bsd.port.mk>
