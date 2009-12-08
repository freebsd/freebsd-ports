# New ports collection makefile for:	expect
# Date created:		17 Oct 1997
# Whom:			taguchi
#
# $FreeBSD$
#

PORTNAME=	expect
PORTVERSION=	5.30
PORTREVISION=	2
CATEGORIES=	japanese lang tk
MASTER_SITES=	ftp://ftp.nist.gov/mel/div826/subject/expect/old/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A sophisticated scripter based on Japanized tcl/tk

LIB_DEPENDS=	tk80jp.1:${PORTSDIR}/japanese/tk80

BROKEN=		does not build
DEPRECATED=	has been broken for 3 months
EXPIRATION_DATE=2010-01-08

USE_AUTOTOOLS=	autoconf:213
CONFIGURE_ENV=	INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
    		CFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--enable-shared --with-tclconfig=${PREFIX}/lib/tcl8.0jp \
		--with-tkconfig=${PREFIX}/lib/tk8.0jp \
		--with-tclinclude=${PREFIX}/include/tcl8.0jp \
		--with-tkinclude=${PREFIX}/include/tk8.0jp

NO_MAN_INSTALL=	yes
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
BROKEN=		Incomplete pkg-plist
.endif

test:
	cd ${WRKSRC} && ${MAKE} test

.include <bsd.port.post.mk>
