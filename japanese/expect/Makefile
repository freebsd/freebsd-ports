# New ports collection makefile for:	expect
# Version required:	5.25
# Date created:		17 Oct 1997
# Whom:			taguchi
#
# $Id: Makefile,v 1.6 1998/02/18 06:28:23 asami Exp $
#

PKGNAME=	ja-expect-5.25
CATEGORIES=	japanese lang tk42

MAINTAINER=	taguchi@tohoku.iij.ad.jp

LIB_DEPENDS=	tk42jp\\.1\\.:${PORTSDIR}/japanese/tk42

FILESDIR=	${.CURDIR}/../../lang/expect/files
CFLAGS=		-DKANJI -DKINPUT2
CONFIGURE_ARGS=	--enable-shared --with-tclconfig=${PREFIX}/lib/tcl7.6jp \
		--with-tkconfig=${PREFIX}/lib/tk4.2jp \
		--with-tclinclude=${PREFIX}/include/tcl7.6jp \
		--with-tkinclude=${PREFIX}/include/tk4.2jp

NO_MAN_INSTALL=	yes

.include "${.CURDIR}/../../lang/expect/Makefile"
