PORTNAME=	tclvfs
DISTVERSION=	1.5.0
CATEGORIES=	filesystems devel
MASTER_SITES=	https://core.tcl-lang.org/tclvfs/tarball/
DISTNAME=	${PORTNAME}-${SNAPSHOT}

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	Tcl VirtualFileSystem layer
WWW=		https://core.tcl-lang.org/tclvfs

LICENSE=       TclTk
LICENSE_NAME=  Tcl/Tk License
LICENSE_FILE=  ${WRKSRC}/license.terms
LICENSE_PERMS= dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libTrf2.1.4.so:devel/tcl-trf

USES+=		gmake tcl:tea
TEST_TARGET=	test

SNAPSHOT=	20260403165307-75a2672991

GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

.include <bsd.port.mk>
