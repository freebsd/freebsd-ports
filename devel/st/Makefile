# New ports collection makefile for:    st
# Date created:         Sun Feb 18 2001
# Whom:                 tobez@tobez.org
#
# $FreeBSD$
#

PORTNAME=	st
PORTVERSION=	1.8
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}ate-threads/${PORTNAME}ate-threads/${PORTVERSION}

MAINTAINER=	lippe@FreeBSD.org
COMMENT=	State Threads Library for Internet Applications

USE_LDCONFIG=	yes
ONLY_FOR_ARCHS=	i386 alpha amd64

DOCS=		fig.gif notes.html reference.html st.html \
		timeout_heap.txt
EXAMPLES=	Makefile README error.c lookupdns.c proxy.c \
		res.c server.c

.include <bsd.port.pre.mk>

post-patch:
	@${RM} -f ${WRKSRC}/Makefile ${WRKSRC}/examples/Makefile
	@${CP} ${FILESDIR}/Makefile.main ${WRKSRC}/Makefile
	@${CP} ${FILESDIR}/Makefile.examples ${WRKSRC}/examples/Makefile

post-install:
	@${CP} ${WRKSRC}/public.h ${PREFIX}/include/st.h
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/docs/,} ${DOCSDIR}/
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${EXAMPLES:S,^,${WRKSRC}/examples/,} ${EXAMPLESDIR}/
.endif

.include <bsd.port.post.mk>
