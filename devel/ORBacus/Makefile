# New ports collection makefile for:	ORBacus
# Date created:		22 June 1998
# Whom:			ejc@bazzle.com
# Version required:	3.0
#
# $Id: Makefile,v 1.15 1998/12/22 07:35:00 asami Exp $
#

DISTNAME=	OB-3.1.1
PKGNAME=	ORBacus-3.1.1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.ooc.com/pub/OB/3.1/

MAINTAINER=	ejc@bazzle.com

.include <bsd.port.pre.mk>

.if ${PORTOBJFORMAT} == "elf"
LIBSTDC=	${PREFIX}/lib/gcc-lib/i386-unknown-freebsdelf${OSREL}/2.8.1/libstdc++.a
.else
LIBSTDC=	${PREFIX}/lib/gcc-lib/i386-unknown-freebsd${OSREL}/2.8.1/libstdc++.a
.endif

BUILD_DEPENDS=  gcc28:${PORTSDIR}/lang/gcc28 \
		g++28:${PORTSDIR}/lang/gcc28 \
		${LIBSTDC}:${PORTSDIR}/lang/glibstdc++28

USE_XLIB=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ENV=	CXX=g++28 CXXFLAGS="-O -pipe"
MAN1=		idl.1
MLINKS=		idl.1 hidl.1	- irdel.1	- irfeed.1 \
		- irgen.1	- irserv.1	- jidl.1

post-install:
	${LDCONFIG} -m ${PREFIX}/lib
	${MKDIR} ${PREFIX}/share/doc/ORBacus
	${INSTALL_DATA} ${WRKSRC}/ob/LICENSE ${PREFIX}/share/doc/ORBacus

.include <bsd.port.mk>
