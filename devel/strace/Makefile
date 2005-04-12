# New ports collection makefile for:	strace
# Date created:		Tue May 15 22:29:27 MSD 2001
# Whom:			Alex Semenyaka <alex@rinet.ru>
#
# $FreeBSD$
#

PORTNAME=	strace
PORTVERSION=	4.5.1
PORTREVISION=	1
CATEGORIES=	devel sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	alex@rinet.ru
COMMENT=	A portable process tracer

USE_BZIP2=	yes
USE_PERL5=	yes # for strace-graph
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
ONLY_FOR_ARCHS=	i386

MAN1=		strace.1

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

post-patch:
	${REINPLACE_CMD} 's,/usr/bin/perl,${PERL},' ${WRKSRC}/strace-graph

do-install:
	${MKDIR} ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/strace ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/strace-graph ${PREFIX}/bin
	${MKDIR} ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/strace.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in AUTHORS COPYRIGHT CREDITS ChangeLog NEWS PORTING \
	README README-freebsd README-svr4 TODO
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
