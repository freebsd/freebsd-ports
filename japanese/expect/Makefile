# New ports collection makefile for:	expect
# Date created:		17 Oct 1997
# Whom:			taguchi
#
# $FreeBSD$
#

PORTNAME=	expect
PORTVERSION=	5.30
CATEGORIES=	japanese lang tk80
MASTER_SITES=	ftp://ftp.nist.gov/mel/div826/subject/expect/old/

MAINTAINER=	taguchi@tohoku.iij.ad.jp

LIB_DEPENDS=	tk80jp.1:${PORTSDIR}/japanese/tk80

USE_AUTOCONF=	yes
CONFIGURE_ENV=	INSTALL_SCRIPT="${INSTALL_SCRIPT}"
CONFIGURE_ARGS=	--enable-shared --with-tclconfig=${PREFIX}/lib/tcl8.0jp \
		--with-tkconfig=${PREFIX}/lib/tk8.0jp \
		--with-tclinclude=${PREFIX}/include/tcl8.0jp \
		--with-tkinclude=${PREFIX}/include/tk8.0jp

NO_MAN_INSTALL=	yes
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

post-install:
.if ${PORTOBJFORMAT} == "aout"
	${LN} -sf libexpect530jp.so.1.2 ${PREFIX}/lib/libexpect530jp.so
.endif

test:
	cd ${WRKSRC} && ${SETENV} PORTOBJFORMAT=${PORTOBJFORMAT} ${MAKE} test 

.include <bsd.port.post.mk>
