# New ports collection makefile for:	strace
# Date created:		Tue May 15 22:29:27 MSD 2001
# Whom:			Alex Semenyaka <alex@rinet.ru>
#
# $FreeBSD$
#

PORTNAME=	strace
PORTVERSION=	4.5.18
PORTREVISION=	1
CATEGORIES=	devel sysutils
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A portable process tracer

USE_BZIP2=	yes
USE_PERL5=	yes # for strace-graph
GNU_CONFIGURE=	yes
ONLY_FOR_ARCHS=	i386

PLIST_FILES=	bin/strace bin/strace-graph

MAN1=		strace.1

.if !defined(NOPORTDOCS)
PORTDOCS=	AUTHORS COPYRIGHT CREDITS ChangeLog NEWS PORTING \
		README README-freebsd README-svr4 TODO
.endif

post-patch:
	${REINPLACE_CMD} 's,/usr/bin/perl,${PERL},' ${WRKSRC}/strace-graph

do-install:
	@${MKDIR} ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/strace ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/strace-graph ${PREFIX}/bin
	@${MKDIR} ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/strace.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>
