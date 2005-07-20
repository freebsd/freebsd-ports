# ports collection makefile for:	yagiuda
# Date created:		19 July 2005
# Whom:			db
#
# $FreeBSD$

PORTNAME=	yagiuda
PORTVERSION=	1.19
CATEGORIES=	comms
MASTER_SITES=	http://www.g8wrb.org/yagi/

MAINTAINER=	db@db.net
COMMENT=	Used to calculate yagi-uda antenna patterns useful to ham radio

GNU_CONFIGURE=	yes
MAN1=		first.1 optimise.1 yagi.1 dipole.1 input.1 output.1
MAN5=		first.5 optimise.5 yagi.5 input.5 output.5

do-install:
.for f in first optimise yagi dipole input output
	${INSTALL_PROGRAM} ${WRKSRC}/src/${f} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/man1/${f}.1 ${PREFIX}/man/man1
.endfor
.for f in first optimise yagi input output
	${INSTALL_MAN} ${WRKSRC}/man/man5/${f}.5 ${PREFIX}/man/man5
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in dipole.1.html input.1.html pattern.jpg\
	first.1.html optimise.1.html yagi.1.html\
	index.html output.1.html yagi.jpg
	${INSTALL_DATA} ${WRKSRC}/doc/$f ${DOCSDIR}
.endfor
	@${ECHO} ""
	@${ECHO} "Additional docs installed in ${DOCSDIR}"
	@${ECHO} ""
.endif

.include <bsd.port.mk>
