# $FreeBSD$

PORTNAME=	bsdcflow
PORTVERSION=	0.0.6
CATEGORIES=	devel
MASTER_SITES=	http://cdn.bitbucket.org/marcusva/cflow/downloads/
DISTNAME=	cflow-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Call graph generator for C and assembler code

CONFLICTS=	gnucflow-[0-9]* cflow-[0-9]*

USES=		gmake
MAKE_ENV=	MANDIR=${PREFIX}/man
MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	bin/asmgraph bin/cgraph	bin/cflow \
		man/man1/asmgraph.1.gz man/man1/cflow.1.gz \
		man/man1/cgraph.1.gz

WRKSRC=		${WRKDIR}/${DISTNAME}/gnu

.include <bsd.port.mk>
