# ex:ts=8
# Ports collection makefile for:	gnucap
# Date created:			Feb 7, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gnucap
PORTVERSION=	0.33
PORTREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Gnu Circuit Analysis Package

USE_REINPLACE=	yes
USE_GMAKE=	yes
HAS_CONFIGURE=	yes
MAKE_ENV=	CXX="${CXX}" CXXFLAGS="${CXXFLAGS}"

CFLAGS+=	-DNEEDS_IS_INF -DNEEDS_IS_NAN

post-patch:
.for file in src/Make2.g++ src/Make.aux modelgen/Make2.g++ modelgen/Make.aux
	@${REINPLACE_CMD} -e "s|-DHAS_READLINE||g ; \
		 s|g\+\+|\$${CXX}|g ; \
		 s|-O2|\$${CXXFLAGS}|g" ${WRKSRC}/${file}
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/modelgen/O/modelgen ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/O/gnucap ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/man
	${INSTALL_DATA} ${WRKSRC}/doc/[a-z]* ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/man/man.pdf ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/man/man/*.html ${WRKSRC}/man/man/*.png \
		${WRKSRC}/man/man/*.css ${DOCSDIR}/man
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.ckt ${WRKSRC}/examples/*.doc \
		${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
