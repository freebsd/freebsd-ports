# New ports collection makefile for:	ORBacus
# Date created:		22 June 1998
# Whom:			ejc@bazzle.com
# Version required:	3.0
#
# $Id: Makefile,v 1.18 1999/04/20 03:36:02 jseger Exp $
#

DISTNAME=	OB-3.1.2
PKGNAME=	ORBacus-3.1.2
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.ooc.com/pub/OB/3.1/

MAINTAINER=	ejc@bazzle.com

.include <bsd.port.pre.mk>

.if ${OSREL} >= 4
LIBSTDC=	/usr/lib/libstdc++.a
CONFIGURE_ENV=	CXX=c++ CXXFLAGS="-O -pipe"
.else
.if ${PORTOBJFORMAT} == "elf"
LIBSTDC=	${PREFIX}/lib/gcc-lib/i386-unknown-freebsdelf${OSREL}/egcs-2.91.62/libstdc++.a
.else
LIBSTDC=	${PREFIX}/lib/gcc-lib/i386-unknown-freebsd${OSREL}/egcs-2.91.62/libstdc++.a
.endif

BUILD_DEPENDS=  eg++:${PORTSDIR}/lang/egcs
CONFIGURE_ENV=	CXX=eg++ CXXFLAGS="-O -pipe"
.endif

USE_XLIB=	yes
HAS_CONFIGURE=	yes
MAN1=		idl.1
MLINKS=		idl.1 hidl.1	- irdel.1	- irfeed.1 \
		- irgen.1	- irserv.1	- jidl.1

post-install:
	${LDCONFIG} -m ${PREFIX}/lib
	${MKDIR} ${PREFIX}/share/doc/ORBacus
	${INSTALL_DATA} ${WRKSRC}/ob/LICENSE ${PREFIX}/share/doc/ORBacus

.include <bsd.port.mk>
