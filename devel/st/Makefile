# New ports collection makefile for:    st
# Date created:         Sun Feb 18 2001
# Whom:                 tobez@tobez.org
#
# $FreeBSD$
#

PORTNAME=	st
PORTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	state-threads

MAINTAINER=	alfred@FreeBSD.org
COMMENT=	State Threads Library for Internet Applications

INSTALLS_SHLIB=	yes
ONLY_FOR_ARCHS=	i386 alpha

.include <bsd.port.pre.mk>

post-patch:
	@${RM} -f ${WRKSRC}/Makefile ${WRKSRC}/examples/Makefile
	@${CP} ${FILESDIR}/Makefile.main ${WRKSRC}/Makefile
	@${CP} ${FILESDIR}/Makefile.examples ${WRKSRC}/examples/Makefile

post-install:
	@${MKDIR} ${PREFIX}/include
	@${INSTALL_DATA} ${WRKSRC}/public.h ${PREFIX}/include/st.h
	@${MKDIR} ${PREFIX}/share/examples/st
	@${INSTALL_DATA} ${WRKSRC}/examples/Makefile	${PREFIX}/share/examples/st
	@${INSTALL_DATA} ${WRKSRC}/examples/README	${PREFIX}/share/examples/st
	@${INSTALL_DATA} ${WRKSRC}/examples/error.c	${PREFIX}/share/examples/st
	@${INSTALL_DATA} ${WRKSRC}/examples/lookupdns.c	${PREFIX}/share/examples/st
	@${INSTALL_DATA} ${WRKSRC}/examples/proxy.c	${PREFIX}/share/examples/st
	@${INSTALL_DATA} ${WRKSRC}/examples/res.c	${PREFIX}/share/examples/st
	@${INSTALL_DATA} ${WRKSRC}/examples/server.c	${PREFIX}/share/examples/st
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/st
	@${INSTALL_DATA} ${WRKSRC}/docs/fig.gif		${PREFIX}/share/doc/st
	@${INSTALL_DATA} ${WRKSRC}/docs/notes.html	${PREFIX}/share/doc/st
	@${INSTALL_DATA} ${WRKSRC}/docs/reference.html	${PREFIX}/share/doc/st
	@${INSTALL_DATA} ${WRKSRC}/docs/st.html		${PREFIX}/share/doc/st
.endif

.include <bsd.port.post.mk>
