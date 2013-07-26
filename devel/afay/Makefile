# Created by: John M. Cooper <john_m_cooper@yahoo.com>
# $FreeBSD$

PORTNAME=	afay
PORTVERSION=	041111
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://thiberlog.free.fr/src/
DISTNAME=	${PORTNAME}_thiberlog_${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	john_m_cooper@yahoo.com
COMMENT=	Improved aflex and ayacc Ada 95 native scanner and parser generators

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash

USES=		ada
MAN1=		aflex.1 ayacc.1
NO_WRKSUBDIR=	yes
OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

do-build:
	@cd ${WRKSRC}/afay/aflex/src/gnat_unix && \
		${SETENV} ${MAKE_ENV} ${SH} ./README
	@cd ${WRKSRC}/afay/ayacc/src/gnat_unix && \
		${SETENV} ${MAKE_ENV} ${SH} ./README

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/afay/aflex/src/aflex ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/afay/ayacc/src/ayacc ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/afay/aflex/doc/aflex.man ${PREFIX}/man/man1/aflex.1
	${INSTALL_DATA} ${WRKSRC}/afay/ayacc/doc/old_docs/ayacc.manpage ${PREFIX}/man/man1/ayacc.1
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DESTDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/afay/aflex/doc/READ_ME ${DOCSDIR}/READ_ME.aflex
	${INSTALL_DATA} ${WRKSRC}/afay/aflex/doc/aflex.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/afay/aflex/doc/aflex_user_man.* ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/afay/ayacc/doc/READ_ME ${DOCSDIR}/READ_ME.ayacc
	${INSTALL_DATA} ${WRKSRC}/afay/ayacc/doc/ayacc.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/afay/ayacc/doc/ayacc_user_man.tex ${DOCSDIR}
.endif
	${MKDIR} ${EXAMPLESDIR}
	${MKDIR} ${EXAMPLESDIR}/ada_parser
	${MKDIR} ${EXAMPLESDIR}/calc
	${INSTALL_DATA} ${WRKSRC}/afay/aflex/doc/example.l ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/afay/aflex/doc/test95.l ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/afay/ayacc/examples/ada_parser/COMPILE ${EXAMPLESDIR}/ada_parser
	${INSTALL_DATA} ${WRKSRC}/afay/ayacc/examples/ada_parser/READ.ME ${EXAMPLESDIR}/ada_parser
	${INSTALL_DATA} ${WRKSRC}/afay/ayacc/examples/ada_parser/ada.y ${EXAMPLESDIR}/ada_parser
	${INSTALL_DATA} ${WRKSRC}/afay/ayacc/examples/ada_parser/ada_lex.l ${EXAMPLESDIR}/ada_parser
	${INSTALL_DATA} ${WRKSRC}/afay/ayacc/examples/ada_parser/driver.a ${EXAMPLESDIR}/ada_parser
	${INSTALL_SCRIPT} ${WRKSRC}/afay/ayacc/examples/calc/COMPILE ${EXAMPLESDIR}/calc
	${INSTALL_DATA} ${WRKSRC}/afay/ayacc/examples/calc/READ.ME ${EXAMPLESDIR}/calc
	${INSTALL_DATA} ${WRKSRC}/afay/ayacc/examples/calc/calc* ${EXAMPLESDIR}/calc
	${INSTALL_DATA} ${WRKSRC}/afay/ayacc/examples/calc/driver.a ${EXAMPLESDIR}/calc

.include <bsd.port.mk>
