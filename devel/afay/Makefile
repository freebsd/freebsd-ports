# Created by: John M. Cooper <john_m_cooper@yahoo.com>
# $FreeBSD$

PORTNAME=	afay
PORTVERSION=	041111
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://thiberlog.free.fr/src/
DISTNAME=	${PORTNAME}_thiberlog_${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	john_m_cooper@yahoo.com
COMMENT=	Improved aflex and ayacc Ada 95 scanner and parser generators

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash

USES=		ada
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
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/afay/aflex/doc/READ_ME \
		${STAGEDIR}${DOCSDIR}/READ_ME.aflex
	(cd ${WRKSRC}/afay/aflex/doc && ${INSTALL_DATA} aflex.html \
		aflex_user_man.* ${STAGEDIR}${DOCSDIR})
	${INSTALL_DATA} ${WRKSRC}/afay/ayacc/doc/READ_ME \
		${STAGEDIR}${DOCSDIR}/READ_ME.ayacc
	(cd ${WRKSRC}/afay/ayacc/doc && ${INSTALL_DATA} ayacc.html \
		ayacc_user_man.tex ${STAGEDIR}${DOCSDIR})
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/ada_parser \
		${STAGEDIR}${EXAMPLESDIR}/calc
	(cd ${WRKSRC}/afay/aflex/doc && ${INSTALL_DATA} example.l test95.l \
		${STAGEDIR}${EXAMPLESDIR})
	${INSTALL_SCRIPT} ${WRKSRC}/afay/ayacc/examples/ada_parser/COMPILE \
		${STAGEDIR}${EXAMPLESDIR}/ada_parser
	(cd ${WRKSRC}/afay/ayacc/examples/ada_parser && \
		${INSTALL_DATA} READ.ME ada.y ada_lex.l driver.a \
		${STAGEDIR}${EXAMPLESDIR}/ada_parser)
	${INSTALL_SCRIPT} ${WRKSRC}/afay/ayacc/examples/calc/COMPILE \
		${STAGEDIR}${EXAMPLESDIR}/calc
	(cd ${WRKSRC}/afay/ayacc/examples/calc && ${INSTALL_DATA} \
		READ.ME calc* driver.a ${STAGEDIR}${EXAMPLESDIR}/calc)
.endif

.include <bsd.port.mk>
