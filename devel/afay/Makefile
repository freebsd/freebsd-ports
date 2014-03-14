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
COMMENT=	Improved aflex and ayacc Ada 95 scanner and parser generators

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash

USES=		ada:47
NO_WRKSUBDIR=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.options.mk>

do-build:
	@cd ${WRKSRC}/afay/aflex/src/gnat_unix && \
		${SETENV} ${MAKE_ENV} ${SH} ./README
	@cd ${WRKSRC}/afay/ayacc/src/gnat_unix && \
		${SETENV} ${MAKE_ENV} ${SH} ./README

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/afay/aflex/src/aflex ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/afay/ayacc/src/ayacc ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/afay/aflex/doc/aflex.man ${STAGEDIR}${PREFIX}/man/man1/aflex.1
	${INSTALL_DATA} ${WRKSRC}/afay/ayacc/doc/old_docs/ayacc.manpage ${STAGEDIR}${PREFIX}/man/man1/ayacc.1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/afay/aflex/doc/READ_ME ${STAGEDIR}${DOCSDIR}/READ_ME.aflex
	${INSTALL_DATA} ${WRKSRC}/afay/aflex/doc/aflex.html ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/afay/aflex/doc/aflex_user_man.* ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/afay/ayacc/doc/READ_ME ${STAGEDIR}${DOCSDIR}/READ_ME.ayacc
	${INSTALL_DATA} ${WRKSRC}/afay/ayacc/doc/ayacc.html ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/afay/ayacc/doc/ayacc_user_man.tex ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/ada_parser
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/calc
	${INSTALL_DATA} ${WRKSRC}/afay/aflex/doc/example.l ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/afay/aflex/doc/test95.l ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/afay/ayacc/examples/ada_parser/COMPILE ${STAGEDIR}${EXAMPLESDIR}/ada_parser
	${INSTALL_DATA} ${WRKSRC}/afay/ayacc/examples/ada_parser/READ.ME ${STAGEDIR}${EXAMPLESDIR}/ada_parser
	${INSTALL_DATA} ${WRKSRC}/afay/ayacc/examples/ada_parser/ada.y ${STAGEDIR}${EXAMPLESDIR}/ada_parser
	${INSTALL_DATA} ${WRKSRC}/afay/ayacc/examples/ada_parser/ada_lex.l ${STAGEDIR}${EXAMPLESDIR}/ada_parser
	${INSTALL_DATA} ${WRKSRC}/afay/ayacc/examples/ada_parser/driver.a ${STAGEDIR}${EXAMPLESDIR}/ada_parser
	${INSTALL_SCRIPT} ${WRKSRC}/afay/ayacc/examples/calc/COMPILE ${STAGEDIR}${EXAMPLESDIR}/calc
	${INSTALL_DATA} ${WRKSRC}/afay/ayacc/examples/calc/READ.ME ${STAGEDIR}${EXAMPLESDIR}/calc
	${INSTALL_DATA} ${WRKSRC}/afay/ayacc/examples/calc/calc* ${STAGEDIR}${EXAMPLESDIR}/calc
	${INSTALL_DATA} ${WRKSRC}/afay/ayacc/examples/calc/driver.a ${STAGEDIR}${EXAMPLESDIR}/calc

.include <bsd.port.mk>
