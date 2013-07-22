# $FreeBSD$

PORTNAME=	bsdcflow
PORTVERSION=	0.0.6
CATEGORIES=	devel
MASTER_SITES=	http://www.sysfault.org/projects/
DISTNAME=	cflow-${PORTVERSION}

MAINTAINER=	mva@FreeBSD.org
COMMENT=	A call graph generator for C and assembler code

CONFLICTS=	gnucflow-[0-9]* cflow-[0-9]*

USE_GMAKE=	yes
MAKE_ENV=	MANDIR=${PREFIX}/man
MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	bin/asmgraph	\
		bin/cgraph	\
		bin/cflow

MAN1=		cflow.1 cgraph.1 asmgraph.1
MANCOMPRESSED=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}/gnu

.include <bsd.port.mk>
