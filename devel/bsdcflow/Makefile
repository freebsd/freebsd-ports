# $FreeBSD$

PORTNAME=	bsdcflow
PORTVERSION=	0.0.6
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://cdn.bitbucket.org/marcusva/cflow/downloads/
DISTNAME=	cflow-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Call graph generator for C and assembler code

LICENSE=	BSD2CLAUSE

CONFLICTS=	gnucflow-[0-9]* cflow-[0-9]*

USES=		gmake
MAKE_ENV=	MANDIR=${PREFIX}/man
MAKE_JOBS_UNSAFE=	yes
WRKSRC_SUBDIR=	gnu

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/cgraph
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/asmgraph

.include <bsd.port.mk>
