# Created by: Stanislav Sedov <ssedov@mbsd.msk.ru>
# $FreeBSD$

PORTNAME=	omake
PORTVERSION=	0.9.8.5
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://main.metaprl.org/download/omake/
DISTNAME=	${PORTNAME}-${PORTVERSION}-3

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A flexible build system

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_OCAML=	yes
NO_OCAML_RUNDEPENDS=yes
USE_NCURSES=	yes
USE_READLINE=	yes
MAKE_JOBS_UNSAFE=	yes

INFO=		omake-doc

.include <bsd.port.pre.mk>

.if ${ARCH} == "powerpc"
BROKEN=		Does not build on powerpc
.endif

post-patch:
#
# Dirty hack for PREFIX safety
#
	@${REINPLACE_CMD} -E -e \
		's|(getenv[[:space:]]+)LIBDIR|\1PREFLIBDIR|' ${WRKSRC}/mk/defaults

#
# Permissions safety
#
.for f in OMakefile doc/OMakefile src/main/OMakefile
	@${REINPLACE_CMD} -e \
		's|cp -f -m 444|$$(BSD_INSTALL_DATA)| ; \
		 s|cp -f -m 555|$$(BSD_INSTALL_PROGRAM)|' ${WRKSRC}/${f}
.endfor

post-install:
	@(cd ${WRKSRC}/doc/info \
		&& ${INSTALL_DATA} omake-doc.info ${PREFIX}/${INFO_PATH})
	@(cd ${WRKSRC}/doc/info \
		&& ${INSTALL_DATA} omake-doc.info-* ${PREFIX}/${INFO_PATH})
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/doc/html && ${COPYTREE_SHARE} . ${DOCSDIR})
.endif

.include <bsd.port.post.mk>
