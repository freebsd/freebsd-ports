# ex:ts=8
# Ports collection makefile for:	ragel
# Date created:			Mar 6, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ragel
PORTVERSION=	6.4
CATEGORIES=	devel
MASTER_SITES=	http://www.complang.org/ragel/
.if !defined(NOPORTDOCS)
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTFILES_DOC}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
.endif

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Compile regular languages into executable C/C++ code

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN1=		${PORTNAME}.1
PORTDOCS=	*
PORTEXAMPLES=	*
PLIST_FILES=	bin/${PORTNAME}

DISTFILES_DOC=	${PORTNAME}-guide-${PORTVERSION}.pdf

post-patch:
	@${REINPLACE_CMD} -e 's|= -g|=|g' ${WRKSRC}/ragel/Makefile.in

post-build:
	@cd ${WRKSRC}/doc && ${SETENV} ${MAKE_ENV} \
		${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} \
		${MAN1}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ragel/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DISTFILES_DOC}
	${INSTALL_DATA} ${DISTDIR}/${file} ${DOCSDIR}
.endfor
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples; ${COPYTREE_SHARE} . ${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
