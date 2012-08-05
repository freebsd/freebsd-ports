# New ports collection makefile for:	server of FreeWnn
# Date created:		00/08/25
# Whom:			Satoshi TAOKA <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	FreeWnn
PORTVERSION=	1.1.1.a021
PORTREVISION=	9
CATEGORIES?=	japanese
MASTER_SITES=	ftp://ftp.freewnn.org/pub/%SUBDIR%/ \
		${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=	FreeWnn/alpha \
			freewnn/17724
PKGNAMESUFFIX=	-server
DISTNAME=	${PORTNAME}-1.1.1-a021

MAINTAINER=	hrs@FreeBSD.org
COMMENT?=	A Japanese/Chinese/Korean input method (Japanese server)

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf libtool
USE_LDCONFIG=	yes
USE_RC_SUBR=	# defined below
MAKE_ARGS=	MANLANG="${MANLANG}" CDEBUGFLAGS="${CFLAGS}" \
		LIBRARY_WNNMANDIR="" \
		SERVER_WNNMANDIR="2.env 4.cmd 6.jutil"
ALL_TARGET=	includes all
INSTALL_TARGET=	install install.man
SUB_FILES=	pkg-install
PKGINSTALL=	${WRKDIR}/pkg-install
MAKE_JOBS_UNSAFE=	yes
USERS=		wnn

WNNTYPE?=	WNN
CONFIGURE_ARGS=	--enable-libraries=no \
		${CONFIGURE_ARGS.${WNNTYPE}}
.if !defined(WITHOUT_INET6)
CONFIGURE_ARGS+=--enable-ipv6
.endif

# Wnn
LIB_DEPENDS.WNN=	wnn.0:${PORTSDIR}/japanese/FreeWnn-lib
CONFIGURE_ARGS.WNN= 	--enable-cWnn=no --enable-kWnn=no \
			--with-libwnn=-lwnn \
			--with-wnn-libraries="${PREFIX}/lib"
MAN1.WNN=	atod.1 atof.1 dtoa.1 jserver.1 oldatonewa.1 uum.1 wddel.1 \
		wdreg.1 wnnkill.1 wnnstat.1 wnntouch.1
MAN4.WNN=	2a_ctrl.4 2b_romkana.4 cvt_key_tbl.4 fzk.data.4 fzk.u.4	\
		hinsi_data.4 jserverrc.4 mode.4 serverdefs.4 ujis_dic.4	\
		uumkey.4 uumrc.4 wnnenvrc.4
MAN5.WNN=	pubdic.5 usr_dic.5
MANLANG.WNN=	ja
USE_RC_SUBR.WNN=	wnn

# CWnn
CONFIGURE_ARGS.CWNN+=	--enable-Wnn=no --enable-kWnn=no		\
			--with-libcwnn=-lcwnn \
			--with-cwnn-libraries="${PREFIX}/lib"
LIB_DEPENDS.CWNN=	cwnn.0:${PORTSDIR}/chinese/FreeWnn-lib
MAN1.CWNN=	cserver.1 cuum.1 cwnnkill.1 cwnnstat.1 catod.1 catof.1	\
		cdicsort.1 cdtoa.1 cwddel.1 cwdreg.1 cwnntouch.1
MAN4.CWNN=	cst_end.4 cwnn.4 cenv.4 ckey.4
USE_RC_SUBR.CWNN=	cwnn twnn

# KWnn
CONFIGURE_ARGS.KWNN+=	--enable-Wnn=no --enable-cWnn=no \
			--with-libkwnn=-lkwnn \
			--with-kwnn-libraries="${PREFIX}/lib"
LIB_DEPENDS.KWNN=	kwnn.0:${PORTSDIR}/korean/FreeWnn-lib
USE_RC_SUBR.KWNN=	kwnn

.for M in LIB_DEPENDS MAN1 MAN4 MAN5 MLINKS MANLANG USE_RC_SUBR
. if defined(${M}.${WNNTYPE})
${M}+=		${${M}.${WNNTYPE}}
. endif
.endfor

post-install:
	${SETENV} PKG_PREFIX=${PREFIX} \
	${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
