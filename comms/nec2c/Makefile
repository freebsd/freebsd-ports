# Created by: db
# $FreeBSD$

PORTNAME=	nec2c
PORTVERSION=	.9
PORTREVISION=	1
CATEGORIES=	comms hamradio
MASTER_SITES=	http://ftp-mirror.internap.com/pub/FreeBSD/distfiles/nec2c/ \
		http://ftp.cerias.purdue.edu/pub/os/FreeBSD/distfiles/nec2c/
DISTNAME=	nec2c

MAINTAINER=	db@FreeBSD.org
COMMENT=	Used to calculate antenna patterns useful to ham radio

LIB_DEPENDS=	ccm:${PORTSDIR}/math/ccmath

NO_STAGE=	yes
post-patch:
	${CP} ${FILESDIR}/carg.c  ${WRKSRC}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/nec2c ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	@${ECHO} ""
	@${ECHO} "nec2c docs installed in ${DOCSDIR}"
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/Input/*.nec ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/Input/*.NEC ${EXAMPLESDIR}
	@${ECHO} "nec2c sample Input files installed in ${EXAMPLESDIR}"
.endif
	@${ECHO} ""
.include <bsd.port.mk>
