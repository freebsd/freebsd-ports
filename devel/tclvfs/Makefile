PORTNAME=	tclvfs
PORTVERSION=	20080503
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}/

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	Tcl VirtualFileSystem layer
WWW=		https://sourceforge.net/projects/tclvfs/

LIB_DEPENDS=	libTrf2.1.4.so:devel/tcl-trf

USES+=		gmake tcl:tea
TCL_PKG=	vfs1.3

GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

.include <bsd.port.mk>
