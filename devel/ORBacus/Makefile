# New ports collection makefile for:	omniBroker
# Date created:		17 May 1997
# Whom:			ejc@bazzle.com
# Version required:	1.0
#
# $Id$
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

.include <bsd.port.mk>
