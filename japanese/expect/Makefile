# New ports collection makefile for:	expect
# Version required:	5.22.0
# Date created:		10 March 1997
# Whom:			taguchi
#
# $Id$
#

FILESDIR=	${.CURDIR}/../../lang/expect/files

.include "${.CURDIR}/../../lang/expect/Makefile"

PKGNAME=	jp-expect-5.22.0
CATEGORIES=	japanese
MAINTAINER=	taguchi@tohoku.iij.ad.jp

LIB_DEPENDS=	tk42jp\\.1\\.:${PORTSDIR}/japanese/tk42

CFLAGS+=	-DKANJI -DKINPUT2
CONFIGURE_ARGS=	--enable-shared --with-tclconfig=${PREFIX}/lib/tcl7.6jp \
		--with-tkconfig=${PREFIX}/lib/tk4.2jp \
		--with-tclinclude=${PREFIX}/include/tcl7.6jp \
		--with-tkinclude=${PREFIX}/include/tk4.2jp
