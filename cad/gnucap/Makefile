# ex:ts=8
# Ports collection makefile for:	gnucap
# Date created:			Feb 7, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gnucap
PORTVERSION=	2005.01.27
CATEGORIES=	cad
MASTER_SITES=	http://www.gnucap.org/devel/ \
		http://www.geda.seul.org/dist/ \
		http://www.kettering.edu/~adavis/gnucap/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/./-/g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Gnu Circuit Analysis Package

USE_GMAKE=	yes
HAS_CONFIGURE=	yes
MAKE_ARGS=	CCC="${CXX}" CCFLAGS="${CXXFLAGS}"

CFLAGS+=	-DUNIX -DNDEBUG -DNEEDS_IS_INF -DNEEDS_IS_NAN -I..

MAN1=		gnucap-ibis.1 gnucap.1

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|echo|true|g' ${WRKSRC}/src/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ibis/O/gnucap-ibis ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/modelgen/O/gnucap-modelgen ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/O/gnucap ${PREFIX}/bin
.for file in *.1
	${INSTALL_MAN} ${WRKSRC}/doc/${file} ${MANPREFIX}/man/man1
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in acs-tutorial history relnotes.* whatisit
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${DOCSDIR}
.endfor
	@${MKDIR} ${DOCSDIR}/man
.for file in *.pdf
	${INSTALL_DATA} ${WRKSRC}/man/${file} ${DOCSDIR}/man
.endfor
	@${MKDIR} ${DOCSDIR}/man/html
.for file in *.html
	${INSTALL_DATA} ${WRKSRC}/man/html/${file} ${DOCSDIR}/man/html
.endfor
	@${MKDIR} ${EXAMPLESDIR}
.for file in README runall *.ckt *.doc
	${INSTALL_DATA} ${WRKSRC}/examples/${file} ${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.post.mk>
