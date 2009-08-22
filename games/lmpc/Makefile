# New ports collection makefile for:	Litte Movie Processing Centre
# Date created:				16 Mar 2006
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	lmpc
PORTVERSION=	3.4.2
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	A tool to manipulate games demo recordings

GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_PERL5_BUILD=	yes

SCRIPTS=	dema dm2cat procdm2.pl
PROGRAMS=	dbs demcut lmpc
PORTDOCS=	README lmpc.html
PLIST_FILES=	${SCRIPTS:S/^/bin\//} ${PROGRAMS:S/^/bin\//}

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
IGNORE=		assumes sizeof(long) == 4
.endif

pre-patch: .SILENT
	${REINPLACE_CMD} -e 's,bin doc src spec,bin src,' ${WRKSRC}/Makefile.in
	# Include <sys/types.h> before <sys/shm.h>, at least alpha needs it
	${ECHO_CMD} -e '37t30\n38d\nwq' | ${ED} -s ${WRKSRC}/src/dbs.c

do-install:
.for s in ${SCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${s} ${PREFIX}/bin
.endfor
.for p in ${PROGRAMS}
	${INSTALL_PROGRAM} ${WRKSRC}/src/${p} ${PREFIX}/bin
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${FILESDIR}/lmpc.html ${DOCSDIR}
.endif

ED?=	/bin/ed

.include <bsd.port.post.mk>
