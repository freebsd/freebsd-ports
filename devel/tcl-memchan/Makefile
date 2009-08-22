# New ports collection makefile for:	TclTrf
# Date created:			May 22, 2000
# Whom:				Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	memchan
PORTVERSION=	2.2.1
PORTREVISION=	1
CATEGORIES=	devel tcl
MASTER_SITES=	SF
PKGNAMEPREFIX=	tcl-

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Two new channel types for in-memory channels in TCL8

BUILD_DEPENDS=	tclsh${TCL_VER}:${PORTSDIR}/lang/tcl${TCL_VER:S/.//}

MAKEFILE=	${FILESDIR}/Makefile.bsd
MAKE_ARGS+=	-j`${SYSCTL} -n hw.ncpu`

USE_TCL=	84+
DDIR=		${PREFIX}/lib/tcl${TCL_VER}/Trf

MAKE_ENV+=	TCL_VER=${TCL_VER} MKDIR="${MKDIR}" \
		PORTVERSION="${PORTVERSION:R}" \
		INSTALL_DATA="${INSTALL_DATA}"

# Too bad, n is no longer an acceptable section for bsd.man.mk
MANN= fifo.n fifo2.n memchan.n memchanapi.n null.n random.n zero.n

post-install:
	cd ${WRKSRC}/doc && ${INSTALL_MAN} ${MANN} ${PREFIX}/man/mann
#.ifndef(NOPORTDOCS)
#	${MKDIR} ${DOCSDIR}
#	${CP} -pR ${WRKSRC}/doc/html/* ${DOCSDIR}
#.endif

.include <bsd.port.mk>

PLIST_SUB!=	${SETENV} TCL_VER=${TCL_VER} ${MAKE} -f ${MAKEFILE} env
