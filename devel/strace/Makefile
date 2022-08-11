PORTNAME=	strace
PORTVERSION=	4.5.18
PORTREVISION=	1
CATEGORIES=	devel sysutils
MASTER_SITES=	SF

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	System call tracer

LICENSE=	BSD3CLAUSE

USES=		cpe shebangfix perl5 tar:bzip2	# perl5 for strace-graph
GNU_CONFIGURE=	yes
ONLY_FOR_ARCHS=	i386
CPE_VENDOR=	strace_project

SHEBANG_FILES=	strace-graph

PLIST_FILES=	bin/strace bin/strace-graph man/man1/strace.1.gz

OPTIONS_DEFINE=	DOCS

PORTDOCS=	AUTHORS COPYRIGHT CREDITS ChangeLog NEWS PORTING \
		README README-freebsd README-svr4 TODO

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 1300088
BROKEN=	Uses procfs-based process debugging
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/strace ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/strace-graph ${STAGEDIR}${PREFIX}/bin

	${INSTALL_MAN} ${WRKSRC}/strace.1 ${STAGEDIR}${MANPREFIX}/man/man1

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
