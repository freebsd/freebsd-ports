# Created by: luigi@FreeBSD.org
# $FreeBSD$

# Maintainers:		Luigi Rizzo <luigi@FreeBSD.org>
#
# This port builds version 2.11.0 of the sane-epkowa driver for SANE.
# (more recent versions do not work - read details below).
#
# The source for sane-epkowa is accessible through
#
#	 http://www.avasys.jp/lx-bin2/linux_e/spc/DL1.do#download
#
# Note that the download interface above requests to fill a form,
# and returns only the most recent version of the software.
# However the license of the software is GPL-like, and the documentation
# coming with the code (README, non-free/AVASYSPL.en.txt) explicitly
# mentions that source redistribution is allowed with no other conditions.
#
# Given that there is no other way for us to get version 2.11.0,
# and since this is allowed by the license, we go straight at the
# URL for the .tar.gz we need.
# The various versions of the code are at:
#
# http://lx1.avasys.jp/iscan/2.7.0/iscan-2.7.0-1.c2.tar.gz
# http://lx1.avasys.jp/iscan/2.8.0/iscan-2.8.0-1.c2.tar.gz
# -- unknown URL for version 2.9.0
# http://lx1.avasys.jp/iscan/2.10.0/iscan_2.10.0-1.tar.gz
# http://lx1.avasys.jp/iscan/2.11.0/iscan_2.11.0-1.tar.gz
# http://lx1.avasys.jp/iscan/2.12.0/iscan_2.12.0-4.tar.gz
# --- version 2.13 never released
# http://lx1.avasys.jp/iscan/2.14.0/iscan_2.14.0-3.tar.gz
# http://linux.avasys.jp/drivers/iscan/2.15.0/iscan_2.15.0-3.tar.gz
#
# Version 2.7.0 to 2.11.0 build on FreeBSD without any patch.
# This port builds version 2.11.0, which is enough to detect the new
# multifunction SX400 scanner/printer that is not supported by the 'epson'
# backend coming with sane-backends.
#
# Version 2.15.0 builds with the patches included with this port,
# but does not work at runtime due to various issues not solved yet.

PORTNAME=	epkowa
PORTVERSION=	2.11.0
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	http://lx1.avasys.jp/iscan/${PORTVERSION}/
DISTNAME=	iscan_${PORTVERSION}-1

MAINTAINER=	cy@FreeBSD.org
COMMENT=	The sane-epkowa driver for FreeBSD

BROKEN=		unfetchable

# use the following two lines for 2.15.0
# MASTER_SITES=http://linux.avasys.jp/drivers/iscan/${PORTVERSION}/
# DISTNAME=	iscan_${PORTVERSION}-3

WRKSRC=${WRKDIR}/iscan-${PORTVERSION}

# We use LIB_DEPENDS, but the dependency is also at build time
LIB_DEPENDS+=	libltdl.so:devel/libltdl
LIB_DEPENDS+=	libgetline.so:devel/libgetline
LIB_DEPENDS+=	libsane.so:graphics/sane-backends

#BUILD_DEPENDS+=	${LOCALBASE}/lib/libltdl.so:devel/libltdl

# gtk libraries are used by the frontend, which we do not build, however
# the configure script relies on that and fails if not present, so as
# a quick fix we set USE_GNOME
USE_GNOME=	gtk20

# The original uses gmake and ./configure
# Also pass appropriate flags to configure to use FreeBSD locations.
USES=		gmake pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--prefix=${PREFIX} LDFLAGS="-L${PREFIX}/lib -lgetline" CPPFLAGS=-I${PREFIX}/include

.include <bsd.port.pre.mk>

.if ${PORTVERSION} != "2.15.0"
do-patch:	# nothing to do

do-build:
	( cd ${WRKSRC}/libltdl ; ${MAKE_CMD} )
	( cd ${WRKSRC}/sanei ; ${MAKE_CMD} )
	( cd ${WRKSRC}/backend ; ${MAKE_CMD} )
	( cd ${WRKSRC}/doc ; ${MAKE_CMD} )
	@${GZIP_CMD} ${WRKSRC}/doc/sane-epkowa.5
.else
.warning version 2.15.0 not working yet
# Remove versioned symbols to link with FreeBSD's [g]libc
post-patch:
	( cd ${WRKSRC}/non-free; ${CP} -p libesmod-i386.so x.so; \
	${OBJCOPY} -R .gnu.version x.so libesmod-i386.so )

# only build the backend part
do-build:
	( cd ${WRKSRC}/backend ; ${MAKE_CMD} )
	( cd ${WRKSRC}/doc ; ${MAKE_CMD} )
	@${GZIP_CMD} ${WRKSRC}/doc/sane-epkowa.5
.endif

do-install:
	${INSTALL_MAN} ${WRKSRC}/doc/sane-epkowa.5.gz ${STAGEDIR}${PREFIX}/man/man5
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/sane ${STAGEDIR}${PREFIX}/etc/sane.d
	${INSTALL_LIB} ${WRKSRC}/backend/.libs/libsane-epkowa.so.1 \
		${STAGEDIR}${PREFIX}/lib/sane/
	@(cd ${STAGEDIR}${PREFIX}/lib/sane; ${LN} -s libsane-epkowa.so.1 libsane-epkowa.so )
	@echo "usb /dev/uscanner0" > ${STAGEDIR}${PREFIX}/etc/sane.d/epkowa.conf.sample

.include <bsd.port.post.mk>
