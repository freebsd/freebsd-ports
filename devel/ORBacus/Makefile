# New ports collection makefile for:	ORBacus
# Date created:		22 June 1998
# Whom:			ejc@bazzle.com
#
# $FreeBSD$
#

PORTNAME=	ORBacus
PORTVERSION=	3.2.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.ooc.com/pub/OB/3.2/ \
		http://ftp.de.sinuspl.net/pub/src/
DISTNAME=	OB-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A CORBA 2 implementation

BROKEN=		"Unfetchable"
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=2004-06-18

RESTRICTED=	"Non-commercial use only"
USE_XLIB=	yes
INSTALLS_SHLIB=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ENV=	CXX="${CXX}" CXXFLAGS="${CXXFLAGS}"
MAN1=		idl.1
MLINKS=		idl.1 hidl.1	- irdel.1	- irfeed.1 \
		- irgen.1	- irserv.1	- jidl.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502000 || ${ARCH} != "i386"
BROKEN=		"Does not compile"
.endif

post-install:
	${MKDIR} ${PREFIX}/share/doc/ORBacus
	${INSTALL_DATA} ${WRKSRC}/ob/LICENSE ${PREFIX}/share/doc/ORBacus

.include <bsd.port.post.mk>
