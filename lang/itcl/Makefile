# New ports collection makefile for:	itcl
# Date created:		Aug 17 1996
# Whom:			chuckr
#
# $FreeBSD$
#

PORTNAME=	itcl
PORTVERSION=	3.0.1
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.tcltk.com/pub/itcl/
DISTNAME=	itcl3.0.1

MAINTAINER=	dmlb@ragnet.demon.co.uk

LIB_DEPENDS=	tcl82.1:${PORTSDIR}/lang/tcl82

WRKSRC=		${WRKDIR}/itcl3.0.1/itcl/unix
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared --with-tcl=${PREFIX}/lib/tcl8.2
CONFIGURE_ENV=	PORTSDIR=${PORTSDIR} ITCL_LIB_FILE=${ITCL_LIB_FILE}
PKGINSTALL=	${PORTSDIR}/lang/tcl82/pkg-install.tclsh
PKGDEINSTALL=	${PORTSDIR}/lang/tcl82/pkg-deinstall.tclsh

SHLIB_MAJOR=	1
SHLIB_MINOR=	1
MAKEFILE=	makefile
ITCL_LIB=	libitcl30.so

MANCOMPRESSED=	yes
MAN1=		itclsh.1
MANN=		body.n class.n code.n configbody.n delete.n ensemble.n find.n
MANN+=		itcl.n itcl_class.n itcl_info.n itclvars.n local.n scope.n

.include <bsd.port.pre.mk>

ITCL_LIB_FILE=	${ITCL_LIB}.${SHLIB_MAJOR}

post-configure:
	@${CP} ${FILESDIR}/Makefile.lib ${WRKSRC}
	@${CP} ${FILESDIR}/makefile     ${WRKSRC}

pre-build:
	@cd ${WRKSRC} && ${MAKE} -f Makefile.lib PREFIX=${PREFIX} \
	   SHLIB_MAJOR=${SHLIB_MAJOR} SHLIB_MINOR=${SHLIB_MINOR} \
	   TCL_PREFIX=${PREFIX}

post-install:
	${LN} -sf ${PREFIX}/bin/itclsh3.0 ${PREFIX}/bin/itclsh
	${LN} -sf ${ITCL_LIB_FILE} ${PREFIX}/lib/${ITCL_LIB}
.if exists(${PKGINSTALL})
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL}
.endif

.include <bsd.port.post.mk>
