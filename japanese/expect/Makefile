# New ports collection makefile for:	expect
# Version required:	5.25
# Date created:		17 Oct 1997
# Whom:			taguchi
#
# $Id: Makefile,v 1.4 1997/10/17 05:58:02 asami Exp $
#

PKGNAME=	ja-expect-5.25
CATEGORIES=	japanese lang

MAINTAINER=	taguchi@tohoku.iij.ad.jp

LIB_DEPENDS=	tk42jp\\.1\\.:${PORTSDIR}/japanese/tk42

FILESDIR=	${.CURDIR}/../../lang/expect/files

NO_MAN_INSTALL=	yes
.include "${.CURDIR}/../../lang/expect/Makefile"

CFLAGS+=	-DKANJI -DKINPUT2
CONFIGURE_ARGS=	--enable-shared --with-tclconfig=${PREFIX}/lib/tcl7.6jp \
		--with-tkconfig=${PREFIX}/lib/tk4.2jp \
		--with-tclinclude=${PREFIX}/include/tcl7.6jp \
		--with-tkinclude=${PREFIX}/include/tk4.2jp

test:
	@(cd ${WRKSRC}; make test)
