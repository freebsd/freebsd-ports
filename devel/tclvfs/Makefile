# Created by: gahr@FreeBSD.org
# $FreeBSD$

PORTNAME=	tclvfs
PORTVERSION=	20080503
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}/

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	Tcl VirtualFileSystem layer

LIB_DEPENDS=	libTrf2.1.4.so:${PORTSDIR}/devel/tcl-trf

USES+=		gmake tcl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-tcl=${TCL_LIBDIR} \
		--prefix=${PREFIX} \
		-exec-prefix=${PREFIX}

.include <bsd.port.mk>
