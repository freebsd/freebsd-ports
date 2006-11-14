# Ports collection makefile for:  afay
# Date created:			  9 Nov 2006
# Whom:				  John M. Cooper
#
# $FreeBSD$
#

PORTNAME=	afay
PORTVERSION=	041111
CATEGORIES=	devel
MASTER_SITES=	http://thiberlog.free.fr/src/
DISTNAME=	${PORTNAME}_thiberlog_${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	john_m_cooper@yahoo.com
COMMENT=	Improved aflex and ayacc Ada 95 native scanner and parser generators

BUILD_DEPENDS=	gnatmake:${PORTSDIR}/lang/gnat \
		bash:${PORTSDIR}/shells/bash

MAN1=		aflex.1 ayacc.1

NO_WRKSUBDIR=	yes

do-build:
	@cd ${WRKSRC}/afay/aflex/src/gnat_unix && ${SH} ./README
	@cd ${WRKSRC}/afay/ayacc/src/gnat_unix && ${SH} ./README

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/afay/aflex/src/aflex ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/afay/ayacc/src/ayacc ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/afay/aflex/doc/aflex.man ${DESTDIR}${PREFIX}/man/man1/aflex.1
	${INSTALL_DATA} ${WRKSRC}/afay/ayacc/doc/old_docs/ayacc.manpage ${DESTDIR}${PREFIX}/man/man1/ayacc.1
.if !defined(NOPORTDOCS)
	${MKDIR} ${DESTDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/afay/aflex/doc/READ_ME ${DESTDIR}${DOCSDIR}/READ_ME.aflex
	${INSTALL_DATA} ${WRKSRC}/afay/aflex/doc/aflex.html ${DESTDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/afay/aflex/doc/aflex_user_man.* ${DESTDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/afay/ayacc/doc/READ_ME ${DESTDIR}${DOCSDIR}/READ_ME.ayacc
	${INSTALL_DATA} ${WRKSRC}/afay/ayacc/doc/ayacc.html ${DESTDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/afay/ayacc/doc/ayacc_user_man.tex ${DESTDIR}${DOCSDIR}
.endif
	${MKDIR} ${DESTDIR}${EXAMPLESDIR}
	${MKDIR} ${DESTDIR}${EXAMPLESDIR}/ada_parser
	${MKDIR} ${DESTDIR}${EXAMPLESDIR}/calc
	${INSTALL_DATA} ${WRKSRC}/afay/aflex/doc/example.l ${DESTDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/afay/aflex/doc/test95.l ${DESTDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/afay/ayacc/examples/ada_parser/COMPILE ${DESTDIR}${EXAMPLESDIR}/ada_parser
	${INSTALL_DATA} ${WRKSRC}/afay/ayacc/examples/ada_parser/READ.ME ${DESTDIR}${EXAMPLESDIR}/ada_parser
	${INSTALL_DATA} ${WRKSRC}/afay/ayacc/examples/ada_parser/ada.y ${DESTDIR}${EXAMPLESDIR}/ada_parser
	${INSTALL_DATA} ${WRKSRC}/afay/ayacc/examples/ada_parser/ada_lex.l ${DESTDIR}${EXAMPLESDIR}/ada_parser
	${INSTALL_DATA} ${WRKSRC}/afay/ayacc/examples/ada_parser/driver.a ${DESTDIR}${EXAMPLESDIR}/ada_parser
	${INSTALL_SCRIPT} ${WRKSRC}/afay/ayacc/examples/calc/COMPILE ${DESTDIR}${EXAMPLESDIR}/calc
	${INSTALL_DATA} ${WRKSRC}/afay/ayacc/examples/calc/READ.ME ${DESTDIR}${EXAMPLESDIR}/calc
	${INSTALL_DATA} ${WRKSRC}/afay/ayacc/examples/calc/calc* ${DESTDIR}${EXAMPLESDIR}/calc
	${INSTALL_DATA} ${WRKSRC}/afay/ayacc/examples/calc/driver.a ${DESTDIR}${EXAMPLESDIR}/calc

.include <bsd.port.mk>
