PORTNAME=	memchan
PORTVERSION=	2.3
PORTREVISION=	2
CATEGORIES=	devel tcl
MASTER_SITES=	SF
PKGNAMEPREFIX=	tcl-
DISTNAME=	Memchan${PORTVERSION}

MAINTAINER=	ports@virtual-estates.net
COMMENT=	Two new channel types for in-memory channels in TCL8
WWW=		https://memchan.sourceforge.net/

BUILD_DEPENDS=	${LOCALBASE}/lib/tcllib/doctools/pkgIndex.tcl:devel/tcllib

WRKSRC=		${WRKDIR}/${DISTNAME}

MAKE_ARGS=	mandir=${PREFIX}/share/man
ALL_TARGET=	binaries libraries doc-old
TEST_TARGET=	test

USES+=		tcl:tea
TCL_PKG=	Memchan${PORTVERSION}

.include <bsd.port.mk>
