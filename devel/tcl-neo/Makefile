# New ports collection makefile for:	NeoTcl
# Date created:			Auf 17, 2001
# Whom:				Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	neotcl
PORTVERSION=	8.2.2
PORTREVISION=	1
CATEGORIES=	devel tcl83
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=nws
DISTNAME=	neowebscript-3.3

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	The NeoTCL part of NeoWebScript -- an Apache TCL mod

LIB_DEPENDS=	tclx83:${PORTSDIR}/lang/tclX \
		db2:${PORTSDIR}/databases/db2

# Not yet -- openldap used db3, neo used db2 :(
#		ldap.2:${PORTSDIR}/net/openldap20-client

SUBDIR=		neowebscript-3.3/neotcl8.3.0-lite/neo${PORTVERSION}
WRKSRC=		${WRKDIR}/${SUBDIR}/generic

EXTRACT_AFTER_ARGS?=	| ${TAR} -xf - ${SUBDIR}/generic ${SUBDIR}/neolibs

MAKEFILE=	${FILESDIR}/Makefile.bsd
MAKE_ENV+=	NEO_LIBRARY=${NEO_LIBRARY}

DDIR=		${PREFIX}/lib/tcl${TCLV}/Trf

post-build:
	cd ${WRKSRC}/../neolibs && ${ECHO_CMD} 'auto_mkindex . */*.tcl' | tclsh8.3

NEO_LIBRARY=	${PREFIX}/lib/neo8.2

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502000
BROKEN=		"Broken pkg-plist"
.endif

post-install:
	${MKDIR} ${NEO_LIBRARY}
	${CP} -Rp ${WRKSRC}/../neolibs/[a-z]* ${NEO_LIBRARY}
	${SED} -e 's,@NEO_SHARED_LIB_FILE@,libneo82.so,' \
		-e 's,@NEO_VERSION@,8.2,' < ${WRKSRC}/pkgIndex.tcl.in > \
		${NEO_LIBRARY}/pkgIndex.tcl

.include <bsd.port.post.mk>
