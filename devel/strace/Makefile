# Created by: Alex Semenyaka <alex@rinet.ru>
# $FreeBSD$

PORTNAME=	strace
PORTVERSION=	4.5.18
PORTREVISION=	1
CATEGORIES=	devel sysutils
MASTER_SITES=	SF

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	System call tracer

LICENSE=	BSD

USES=		shebangfix
USE_BZIP2=	yes
USE_PERL5=	yes # for strace-graph
GNU_CONFIGURE=	yes
ONLY_FOR_ARCHS=	i386

SHEBANG_FILES=	strace-graph

MAN1=		strace.1
PLIST_FILES=	bin/strace bin/strace-graph

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	AUTHORS COPYRIGHT CREDITS ChangeLog NEWS PORTING \
		README README-freebsd README-svr4 TODO
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/strace ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/strace-graph ${PREFIX}/bin

	${INSTALL_MAN} ${WRKSRC}/strace.1 ${MANPREFIX}/man/man1

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>
