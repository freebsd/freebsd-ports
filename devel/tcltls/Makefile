# New ports collection makefile for:	tclgetopts
# Date created:				4 May 2000
# Whom:					mi@aldan.algebra.com
#
# $FreeBSD$
#

PORTNAME=	tcltls
PORTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	devel tcl83
MASTER_SITES=	${MASTER_SITE_TCLTK}
MASTER_SITE_SUBDIR=tls
DISTNAME=	tls${PORTVERSION}

MAINTAINER=	mi@aldan.algebra.com

LIB_DEPENDS+=	tcl${TCLVND}:${PORTSDIR}/lang/tcl${TCLVND}

USE_OPENSSL=	Yes

pre-patch:
	# Fixing the end-of-lines:
	for f in `find ${WRKSRC}/.. -type f` ; do \
		${TR} -d '\015' < $$f > $$f.noms && \
			${CAT} $$f.noms > $$f && ${RM} $$f.noms; done

PLIST_SUB+=	TCL_VER=${TCL_VER} DISTNAME="${DISTNAME}"
MAKEFILE=	${FILESDIR}/Makefile.bsd
MAKE_ENV=	TCL_VER=${TCL_VER} MKDIR="${MKDIR}" \
		INSTALL_DATA="${INSTALL_DATA}" \
		OPENSSLINC="${OPENSSLINC}" OPENSSLLIB="${OPENSSLLIB}" \
		OPENSSLDIR="${OPENSSLDIR}" CFLAGS="${CFLAGS}" \
		PORTVERSION="${PORTVERSION}" SED="${SED}"

post-install:
	${MKDIR} ${PREFIX}/share/doc/tls
	${INSTALL_DATA} ${WRKSRC}/tls.htm ${PREFIX}/share/doc/tls/

TCL_VER?=	8.3
TCLVND=		${TCL_VER:S/.//}

.include <bsd.port.mk>

PLIST_SUBP!=	${SETENV} ${MAKE_ENV} ${MAKE} -f ${MAKEFILE} environ
PLIST_SUB+=	${PLIST_SUBP}
