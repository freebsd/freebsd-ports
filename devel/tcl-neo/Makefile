# New ports collection makefile for:	NeoTcl
# Date created:			Auf 17, 2001
# Whom:				Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	neotcl
PORTVERSION=	8.2.2
PORTREVISION=	3
CATEGORIES=	devel tcl
MASTER_SITES=	SF/nws/nws/3.3
DISTNAME=	neowebscript-3.3

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	The NeoTCL part of NeoWebScript -- an Apache TCL mod

LIB_DEPENDS=	db2:${PORTSDIR}/databases/db2
BUILD_DEPENDS=	${LOCALBASE}/include/tclExtend.h:${PORTSDIR}/lang/tclX
RUN_DEPENDS=	${BUILD_DEPENDS}

# Not yet -- openldap used db3, neo used db2 :(
#		ldap.2:${PORTSDIR}/net/openldap20-client

USE_LDCONFIG=	yes

SUBDIR=		neowebscript-3.3/neotcl8.3.0-lite/neo${PORTVERSION}
WRKSRC=		${WRKDIR}/${SUBDIR}/generic

EXTRACT_AFTER_ARGS?=	| ${TAR} -xf - ${SUBDIR}/generic ${SUBDIR}/neolibs

MAKEFILE=	${FILESDIR}/Makefile.bsd
TCL_VER?=	8.4
MAKE_ENV+=	NEO_LIBRARY=${NEO_LIBRARY} TCL_VER=${TCL_VER}

DDIR=		${PREFIX}/lib/tcl${TCLV}/Trf

post-build:
	cd ${WRKSRC}/../neolibs && ${ECHO_CMD} 'auto_mkindex . */*.tcl' | tclsh${TCL_VER}

NEO_LIBRARY=	${PREFIX}/lib/neo8.2

.include <bsd.port.pre.mk>

post-install:
	${MKDIR} ${NEO_LIBRARY}
	${CP} -Rp ${WRKSRC}/../neolibs/[a-z]* ${NEO_LIBRARY}
	${SED} -e 's,@NEO_SHARED_LIB_FILE@,libneo82.so,' \
		-e 's,@NEO_VERSION@,8.2,' < ${WRKSRC}/pkgIndex.tcl.in > \
		${NEO_LIBRARY}/pkgIndex.tcl

.include <bsd.port.post.mk>
