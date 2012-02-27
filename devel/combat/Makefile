# New ports collection Makefile for:	combat
# Date created:				24 February 2012
# Whom:					gahr
#
# $FreeBSD$
#

PORTNAME=	combat
PORTVERSION=	0.8.1
CATEGORIES=	devel
MASTER_SITES=	http://www.fpx.de/Combat/download/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A CORBA ORB implementation in Tcl

LICENSE=	BSD

LIB_DEPENDS=	itcl.3:${PORTSDIR}/lang/itcl
RUN_DEPENDS=	idl:${PORTSDIR}/devel/mico

USE_TCL=	yes
NO_BUILD=	yes

PORTDOCS=	*
PORTEXAMPLES=	*

.include <bsd.port.pre.mk>

do-install:
	cd ${WRKSRC}/orb && ${COPYTREE_SHARE} \* ${PREFIX}/lib/combat
	${MKDIR} ${PREFIX}/bin/combat
	${INSTALL_SCRIPT} ${WRKSRC}/bin/idl2tcl ${PREFIX}/bin/combat
	${INSTALL_SCRIPT} ${WRKSRC}/bin/iordump ${PREFIX}/bin/combat
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/combat.pdf ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/demo && ${COPYTREE_SHARE} \* ${EXAMPLESDIR}
.endif

test:
	cd ${WRKSRC}/test && ${MAKE} test

.include <bsd.port.post.mk>
