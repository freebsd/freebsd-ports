# New ports collection makefile for:	tkcvs
# Date created:         02 Aug 1996
# Whom:                 shanee@augusta.de
#
# $FreeBSD$
#

PORTNAME=	tkcvs
PORTVERSION=	6.4
CATEGORIES=	devel tk82
MASTER_SITES=	http://www.twobarleycorns.net/

MAINTAINER=	shanee@augusta.de

LIB_DEPENDS=	tk82.1:${PORTSDIR}/x11-toolkits/tk82

NO_BUILD=	yes
MANN=		tkcvs.n

WISH=		wish8\.2
TCLSH=		tclsh8\.2

post-patch:
	@${PERL} -pi -e 's|wish|${WISH}|g' ${WRKSRC}/tkcvs/tkcvs.blank
	@${PERL} -pi -e 's|wish|${WISH}|g' ${WRKSRC}/tkdiff/tkdiff
	@${PERL} -pi -e 's|wish|${WISH}|g' ${WRKSRC}/doinstall.tcl

do-install:
	(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${TCLSH} doinstall.tcl)

post-install:
.if !defined{NOPORTDOCS}
	${MKDIR} ${PREFIX}/share/doc/tkcvs
	${INSTALL_DATA} ${WRKSRC}/README.tkcvs ${PREFIX}/share/doc/tkcvs/
.endif

.include <bsd.port.mk>
