# New ports collection makefile for:	itcl
# Version required:	3.0.1
# Date created:		Aug 17 1996
# Whom:			chuckr
#
# $FreeBSD$
#

DISTNAME=	itcl3.0.1
PKGNAME=	itcl-3.0.1
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.tcltk.com/pub/itcl/

MAINTAINER=	dmlb@ragnet.demon.co.uk

LIB_DEPENDS=	tcl80.1:${PORTSDIR}/lang/tcl80

WRKSRC=		${WRKDIR}/itcl3.0.1/itcl/unix
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared --with-tcl=${PREFIX}/lib/tcl8.0
CONFIGURE_ENV=	PORTSDIR=${PORTSDIR} ITCL_LIB_FILE=${ITCL_LIB_FILE}

SHLIB_MAJOR=	1
SHLIB_MINOR=	1
MAKEFILE=	makefile
ITCL_LIB=	libitcl30.so

MANCOMPRESSED=	yes
MAN1=		itclsh.1
MANN=		body.n class.n code.n configbody.n delete.n ensemble.n find.n
MANN+=		itcl.n itcl_class.n itcl_info.n itclvars.n local.n scope.n

.include <bsd.port.pre.mk>

.if ${PORTOBJFORMAT} == "elf"
ITCL_LIB_FILE=	${ITCL_LIB}.${SHLIB_MAJOR}
.else
ITCL_LIB_FILE=	${ITCL_LIB}.${SHLIB_MAJOR}.${SHLIB_MINOR}
.endif

post-configure:
	@${CP} ${FILESDIR}/Makefile.lib ${WRKSRC}
	@${CP} ${FILESDIR}/makefile     ${WRKSRC}

pre-build:
	@cd ${WRKSRC} && ${MAKE} -f Makefile.lib PREFIX=${PREFIX} \
	   SHLIB_MAJOR=${SHLIB_MAJOR} SHLIB_MINOR=${SHLIB_MINOR} \
	   TCL_PREFIX=${PREFIX}

post-install:
	${LN} -sf ${ITCL_LIB_FILE} ${PREFIX}/lib/${ITCL_LIB}
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.post.mk>
