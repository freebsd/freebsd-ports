# Created by:				Dave Grochowski
# $FreeBSD$

PORTNAME=	gccmakedep
PORTVERSION=	1.0.2
CATEGORIES=	devel

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Create dependencies in makefiles using 'gcc -M'

XORG_CAT=	util

MAN1=		gccmakedep.1

PLIST_FILES=	bin/gccmakedep

.include <bsd.port.pre.mk>

.if defined(CC) && ${CC:T:M*clang*} == "clang" || ${OSVERSION} >= 1000024
BUILD_DEPENDS+=	ucpp:${PORTSDIR}/devel/ucpp
RUN_DEPENDS+=	ucpp:${PORTSDIR}/devel/ucpp
CONFIGURE_ENV+=	ac_cv_path_RAWCPP="ucpp -s"
.endif

.include <bsd.port.post.mk>
