# New ports collection makefile for:	TclTrf
# Date created:			May 22, 2000
# Whom:				Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	memchan
PORTVERSION=	2.2a2
CATEGORIES=	devel tcl83
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
PKGNAMEPREFIX=	tcl-
DISTNAME=	memchan${PORTVERSION}
MASTER_SITE_SUBDIR=${PORTNAME}

MAINTAINER=	mi@aldan.algebra.com

BUILD_DEPENDS=	tclsh${TCL_VER}:${PORTSDIR}/lang/tcl${TCL_VER:S/.//}

USE_BZIP2=	yes

MAKEFILE=	${FILESDIR}/Makefile.bsd
MAKE_ARGS+=	-j2

TCL_VER?=		8.3
DDIR=		${PREFIX}/lib/tcl${TCL_VER}/Trf

MAKE_ENV+=	TCL_VER=${TCL_VER} MKDIR="${MKDIR}" \
		INSTALL_DATA="${INSTALL_DATA}"

# Too bad, n is no longer an acceptable section for bsd.man.mk
MANN=	memchan.n fifo.n fifo2.n null.n

post-install:
	cd ${WRKSRC}/doc && ${INSTALL_MAN} ${MANN} ${PREFIX}/man/mann
#.ifndef(NOPORTDOCS)
#	${MKDIR} ${DOCSDIR}
#	${CP} -pR ${WRKSRC}/doc/html/* ${DOCSDIR}
#.endif

.include <bsd.port.mk>

PLIST_SUB!=	${SETENV} TCL_VER=${TCL_VER} ${MAKE} -f ${MAKEFILE} env
