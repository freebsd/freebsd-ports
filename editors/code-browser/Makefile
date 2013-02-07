# Created by: ijliao
# $FreeBSD$

PORTNAME=	code-browser
PORTVERSION=	4.6
CATEGORIES=	editors
MASTER_SITES=	http://tibleiz.net/download/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Folding text editor

BUILD_DEPENDS=	copper-llvm:${PORTSDIR}/lang/copper

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_GNOME=	gtk20
USE_GMAKE=	yes
MAKE_JOBS_UNSAFE=	yes

DATADIR=	${PREFIX}/share/${PORTNAME}-4

.include <bsd.port.pre.mk>

ONLY_FOR_ARCHS=		i386 amd64 sparc64
ONLY_FOR_ARCHS_REASON=	does not build on ${ARCH}; signal 11 errors during build

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g ; \
		 s|^CC|#CC|g ; \
		 s|^CFLAGS|#CFLAGS|g ; \
		 s|x86_64|amd64|g ; \
		 s|@$$(|$$(|g' ${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
	(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} \* ${DOCSDIR})
	(cd ${WRKSRC}/samples && ${COPYTREE_SHARE} \* ${DOCSDIR}/samples)
.endif

.include <bsd.port.post.mk>
