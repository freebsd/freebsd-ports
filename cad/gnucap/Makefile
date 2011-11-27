# ex:ts=8
# Ports collection makefile for:	gnucap
# Date created:			Feb 7, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gnucap
PORTVERSION=	2009.12.07
CATEGORIES=	cad
MASTER_SITES=	http://www.gnucap.org/devel/ \
		http://www.gnucap.org/devel/archive/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/./-/g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The GNU Circuit Analysis Package

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

MAN1=		gnucap.1 gnucap-ibis.1
PORTDOCS=	*
PORTEXAMPLES=	*
PLIST_FILES=	bin/gnucap bin/gnucap-modelgen

post-patch:
	${REINPLACE_CMD} -e \
		'/^SUBDIRS/s|doc examples||' ${WRKSRC}/Makefile.in

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/*.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/acs-tutorial ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/history ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/relnotes.* ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/whatisit ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/README ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/runall ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.c ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.ckt ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.doc ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
