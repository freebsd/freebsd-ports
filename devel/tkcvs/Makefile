# New ports collection makefile for:	tkcvs
# Date created:         02 Aug 1996
# Whom:                 shanee@augusta.de
#
# $FreeBSD$
#

PORTNAME=	tkcvs
PORTVERSION=	7.0.3
CATEGORIES=	devel tk83
MASTER_SITES=	http://www.twobarleycorns.net/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/./_/:S/.//g}

MAINTAINER=	shanee@augusta.de

LIB_DEPENDS=	tk83.1:${PORTSDIR}/x11-toolkits/tk83

NO_BUILD=	yes
MAN1=		tkcvs.1

WISH=		wish8\.3
TCLSH=		tclsh8\.3

post-patch:
	@${PERL} -pi -e 's|wish|${WISH}|g' ${WRKSRC}/tkcvs/tkcvs.blank
	@${PERL} -pi -e 's|wish|${WISH}|g' ${WRKSRC}/tkdiff/tkdiff
	@${PERL} -pi -e 's|wish|${WISH}|g' ${WRKSRC}/doinstall.tcl

do-install:
	cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${TCLSH} doinstall.tcl -nox ${PREFIX}

post-install:
.if !defined{NOPORTDOCS}
	${MKDIR} ${PREFIX}/share/doc/tkcvs
	${INSTALL_DATA} ${WRKSRC}/README.tkcvs ${PREFIX}/share/doc/tkcvs/
.endif

.include <bsd.port.mk>
