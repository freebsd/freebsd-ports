# New ports collection makefile for:	ORBacus
# Date created:		22 June 1998
# Whom:			ejc@bazzle.com
# Version required:	3.0b1
#
# $Id: Makefile,v 1.8 1998/07/20 22:15:31 steve Exp $
#

DISTNAME=	OB-3.0
PKGNAME=	ORBacus-3.0
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.ooc.com/pub/OB/3.0/

MAINTAINER=	ejc@bazzle.com

BUILD_DEPENDS=  gcc28:${PORTSDIR}/lang/gcc28 \
		g++28:${PORTSDIR}/lang/gcc28 \
		${PREFIX}/lib/gcc-lib/i386-unknown-freebsd3.0/2.8.1/libstdc++.a:${PORTSDIR}/lang/glibstdc++28

BROKEN=		build

HAS_CONFIGURE=	yes
CONFIGURE_ENV=	CXX=g++28 CXXFLAGS="-O -pipe"
MAN1=		idl.1

post-install:
	${LDCONFIG} -m ${PREFIX}/lib
	${MKDIR} ${PREFIX}/share/doc/ORBacus
	${INSTALL_DATA} ${WRKSRC}/ob/LICENSE ${PREFIX}/share/doc/ORBacus

.include <bsd.port.mk>
