# New ports collection makefile for:	ORBacus
# Date created:		22 June 1998
# Whom:			ejc@bazzle.com
# Version required:	3.0
#
# $FreeBSD$
#

DISTNAME=	OB-3.1.3
PKGNAME=	ORBacus-3.1.3
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.ooc.com/pub/OB/3.1/

MAINTAINER=	ejc@bazzle.com

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 400004
LIBSTDC=	/usr/lib/libstdc++.a
.else
.if ${PORTOBJFORMAT} == "elf"
LIBSTDC=	${PREFIX}/lib/gcc-lib/${ARCH}-portbld-freebsd${OSREL}/2.95.1/libstdc++.a
.else
LIBSTDC=	${PREFIX}/lib/gcc-lib/${ARCH}-portbld-freebsdaout${OSREL}/2.95.1/libstdc++.a
.endif
.endif

USE_XLIB=	yes
HAS_CONFIGURE=	yes
USE_NEWGCC=	yes
CONFIGURE_ENV=	CXX="${CXX}" CXXFLAGS="${CXXFLAGS}"
MAN1=		idl.1
MLINKS=		idl.1 hidl.1	- irdel.1	- irfeed.1 \
		- irgen.1	- irserv.1	- jidl.1

post-install:
	${LDCONFIG} -m ${PREFIX}/lib
	${MKDIR} ${PREFIX}/share/doc/ORBacus
	${INSTALL_DATA} ${WRKSRC}/ob/LICENSE ${PREFIX}/share/doc/ORBacus

.include <bsd.port.post.mk>
