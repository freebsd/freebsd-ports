# New ports collection makefile for:	tkcvs
# Date created:         02 Aug 1996
# Whom:                 shanee@augusta.de
#
# $FreeBSD$
#

PORTNAME=	tkcvs
PORTVERSION=	7.2
CATEGORIES=	devel
MASTER_SITES=	http://www.twobarleycorns.net/
DISTNAME=	${PORTNAME}_${PORTVERSION:S/./_/g}

MAINTAINER=	shanee@augusta.de
COMMENT=	Tcl/Tk frontends to CVS and diff

LIB_DEPENDS=	tk84.1:${PORTSDIR}/x11-toolkits/tk84

NO_BUILD=	yes
MAN1=		tkcvs.1
USE_REINPLACE=	yes

WISH=		wish8.4
TCLSH=		tclsh8.4

post-patch:
	@${REINPLACE_CMD} -e 's|wish|${WISH}|g' ${WRKSRC}/tkcvs/tkcvs.blank \
		${WRKSRC}/tkdiff/tkdiff ${WRKSRC}/doinstall.tcl

do-install:
	cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${TCLSH} doinstall.tcl -nox ${PREFIX}

post-install:
.if !defined{NOPORTDOCS}
	${MKDIR} ${PREFIX}/share/doc/tkcvs
	${INSTALL_DATA} ${WRKSRC}/README.tkcvs ${PREFIX}/share/doc/tkcvs/
.endif

.include <bsd.port.mk>
