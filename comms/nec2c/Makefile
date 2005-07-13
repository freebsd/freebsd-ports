# ports collection makefile for:	splat
# Date created:		8 July 2005
# Whom:			db
#
# $FreeBSD$

PORTNAME=	nec2c
PORTVERSION=	.9
CATEGORIES=	comms
MASTER_SITES=	http://www.si-list.org/NEC_Archives/
DISTNAME=	nec2c
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	db@db.net
COMMENT=	Used to calculate antenna patterns useful to ham radio

#
# both libccm and files/carg.c can "go away" once libc is filled in
# with missing posix complex functions.
#
LIB_DEPENDS=	ccm:${PORTSDIR}/math/ccmath

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		"does not build (gcc does not understand complex numbers)"
.endif

post-patch:
	${CP} ${FILESDIR}/carg.c  ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nec2c ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/Input/*.nec ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/Input/*.NEC ${EXAMPLESDIR}
	@${ECHO} ""
	@${ECHO} "nec2c docs installed in ${DOCSDIR}"
	@${ECHO} "nec2c sample Input files installed in ${EXAMPLESDIR}"
	@${ECHO} ""
.endif

.include <bsd.port.post.mk>
