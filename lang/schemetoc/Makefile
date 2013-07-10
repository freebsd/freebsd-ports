# Created by: jmacd@uclink.berkeley.edu
# $FreeBSD$

PORTNAME=	schemetoc
PORTVERSION=	93.3.15
PORTREVISION=	2
CATEGORIES=	lang scheme
MASTER_SITES=	http://www.cs.indiana.edu/pub/scheme-repository/imp/Scheme-to-C/
DISTNAME=	15mar93
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	erik@bz.bzflag.bz
COMMENT=	Scheme-to-C, a compiler and interpreter for compiling scheme into C

ONLY_FOR_ARCHS=	i386

MAKE_JOBS_UNSAFE=	yes
USE_LDCONFIG=	yes
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
		s|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/scsc/*.sc

.include <bsd.port.mk>
