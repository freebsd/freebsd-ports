# New ports collection makefile for:	robodoc
# Version required:			3.1e
# Date created:				15 Dec 1999
# Whom:					Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

DISTNAME=	robodoc
PKGNAME=	robodoc-3.1e
CATEGORIES=	devel
MASTER_SITES=	http://www.xs4all.nl/~rfsber/Robo/
EXTRACT_SUFX=	.tgz

MAINTAINER=	will@FreeBSD.org

FETCH_BEFORE_ARGS+= -b
WRKSRC=		${WRKDIR}/Robodoc
MAKEFILE=	makefile
USE_GMAKE=	yes
MAN1=		robodoc.1

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/Source/robodoc ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/Docs/robodoc.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/robodoc
.for DOC in example.c general.m4 main.css robodoc.html robodoc.m4 \
	    stoc.html stoc.m4 tocgen.m4
	@${INSTALL_DATA} ${WRKSRC}/Docs/${DOC} ${PREFIX}/share/robodoc
.endfor
	@${ECHO}
	@${ECHO} "Docs installed in ${PREFIX}/share/robodoc."
	@${ECHO}
.endif

.include <bsd.port.mk>
