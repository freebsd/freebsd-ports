# New ports collection makefile for:	Scheme-to-C
# Date created:		28 Dec 1994
# Whom:			jmacd@uclink.berkeley.edu
#
# $FreeBSD$
#

PORTNAME=	schemetoc
PORTVERSION=	93.3.15
CATEGORIES=	lang scheme
MASTER_SITES=	http://www.cs.indiana.edu/pub/scheme-repository/imp/Scheme-to-C/
DISTNAME=	15mar93
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	erik@smluc.org
COMMENT=	Scheme-to-C, a compiler and interpreter for compiling scheme into C

USE_XLIB=	yes
USE_GCC=	2.95
INSTALLS_SHLIB=	yes
NO_WRKSUBDIR=	yes
MAN1=		scc.1 sci.1

post-extract:
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}
	@${CP} ${FILESDIR}/README.FreeBSD ${WRKSRC}
	@${MV} ${WRKDIR}/scsc/main.c ${WRKSRC}/scsc/main.c.orig
	@${CP} ${FILESDIR}/main.c ${WRKSRC}/scsc/main.c
	@${MKDIR} ${WRKDIR}/ports/FREEBSD
.for file in makefile-head options-server.h options.h x86.s
	@${CP} ${FILESDIR}/${file} ${WRKSRC}/ports/FREEBSD
.endfor

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g; \
		s|%%X11BASE%%|${X11BASE}|g' ${WRKSRC}/scsc/*.sc

.include <bsd.port.mk>
