# ports collection makefile for:	splat
# Date created:		8 July 2005
# Whom:			db
#
# $FreeBSD$
# http://5b4az.chronos.org.uk/pkg/nec2/nec2c/nec2c-0.6.tar.gz
# http://ftp-mirror.internap.com/pub/FreeBSD/distfiles/nec2c/nec2c.tar.gz
# http://ftp.cerias.purdue.edu/pub/os/FreeBSD/distfiles/nec2c/nec2c.tar.gz
#
PORTNAME=	nec2c
PORTVERSION=	.9
CATEGORIES=	comms hamradio
MASTER_SITES=	http://ftp-mirror.internap.com/pub/FreeBSD/distfiles/nec2c/ \
		http://ftp.cerias.purdue.edu/pub/os/FreeBSD/distfiles/nec2c/
DISTNAME=	nec2c

MAINTAINER=	db@db.net
COMMENT=	Used to calculate antenna patterns useful to ham radio

#
# both libccm and files/carg.c can "go away" once libc is filled in
# with missing posix complex functions.
#
LIB_DEPENDS=	ccm:${PORTSDIR}/math/ccmath

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
USE_GCC=	3.4+
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
