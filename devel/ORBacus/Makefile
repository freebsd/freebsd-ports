# New ports collection makefile for:	ORBacus
# Date created:		22 June 1998
# Whom:			ejc@bazzle.com
# Version required:	3.0
#
# $Id: Makefile,v 1.10 1998/07/29 12:12:42 ejc Exp $
#

DISTNAME=	OB-3.0
PKGNAME=	ORBacus-3.0
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.ooc.com/pub/OB/3.0/

MAINTAINER=	ejc@bazzle.com

BUILD_DEPENDS=  gcc28:${PORTSDIR}/lang/gcc28 \
		g++28:${PORTSDIR}/lang/gcc28 \
		${PREFIX}/lib/gcc-lib/i386-unknown-freebsd${OSREL}/2.8.1/libstdc++.a:${PORTSDIR}/lang/glibstdc++28

HAS_CONFIGURE=	yes
CONFIGURE_ENV=	CXX=g++28 CXXFLAGS="-O -pipe"
MAN1=		idl.1

post-install:
	${LDCONFIG} -m ${PREFIX}/lib
	${MKDIR} ${PREFIX}/share/doc/ORBacus
	${INSTALL_DATA} ${WRKSRC}/ob/LICENSE ${PREFIX}/share/doc/ORBacus
.for man in hidl irdel irfeed irgen irserv jidl
	${RM} -f ${PREFIX}/man/man1/${man}.1*
.if defined(NOMANCOMPRESS)
	${LN} -sf idl.1 ${PREFIX}/man/man1/${man}.1
.else
	${LN} -sf idl.1.gz ${PREFIX}/man/man1/${man}.1.gz
.endif
.endfor

.include <bsd.port.mk>
