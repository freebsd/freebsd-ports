# New ports collection makefile for:	expect
# Version required:	5.26
# Date created:		17 Oct 1997
# Whom:			taguchi
#
# $Id: Makefile,v 1.7 1998/02/22 08:35:03 fenner Exp $
#

DISTNAME=	expect-5.26
PKGNAME=	ja-expect-5.26
CATEGORIES=	japanese lang tk42

MAINTAINER=	taguchi@tohoku.iij.ad.jp

LIB_DEPENDS=	tk80jp\\.1\\.:${PORTSDIR}/japanese/tk80

FILESDIR=	${.CURDIR}/../../lang/expect/files
GNU_CONFIGURE=	yes
USE_AUTOCONF=	yes
CFLAGS=		-DKANJI -DKINPUT2
CONFIGURE_ENV=	INSTALL_SCRIPT="${INSTALL_SCRIPT}"
CONFIGURE_ARGS=	--enable-shared --with-tclconfig=${PREFIX}/lib/tcl8.0jp \
		--with-tkconfig=${PREFIX}/lib/tk8.0jp \
		--with-tclinclude=${PREFIX}/include/tcl8.0jp \
		--with-tkinclude=${PREFIX}/include/tk8.0jp

NO_MAN_INSTALL=	yes

.include "${.CURDIR}/../../lang/expect/Makefile"
