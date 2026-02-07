PORTNAME=	bsdcflow
PORTVERSION=	0.0.6
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://cdn.bitbucket.org/marcusva/cflow/downloads/
DISTNAME=	cflow-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Call graph generator for C and assembler code
WWW=		https://bitbucket.org/marcusva/cflow

LICENSE=	BSD2CLAUSE

CONFLICTS=	gnucflow cflow

USES=		gmake
MAKE_ENV=	MANDIR=${PREFIX}/share/man
MAKE_JOBS_UNSAFE=	yes
WRKSRC_SUBDIR=	gnu

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/cgraph
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/asmgraph

.include <bsd.port.mk>
