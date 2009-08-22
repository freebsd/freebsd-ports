# New ports collection makefile for:	vym
# Date created:				17 Oct 2004
# Whom:			Gerrit Beine <tux@pinguru.net>
#
# $FreeBSD$
#

PORTNAME=	vym
PORTVERSION=	1.12.2
CATEGORIES=	deskutils
MASTER_SITES=	SF

MAINTAINER=	gerrit.beine@gmx.de
COMMENT=	VYM  (View Your Mind) is a tool to generate and manipulate maps

USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	qmake_build uic_build moc_build qt3support network xml

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${QMAKE} \
		-spec ${QMAKESPEC} vym.pro

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
.for dir in exports flags icons lang macros scripts styles
	@cd ${WRKSRC} && \
	    ${FIND} ${dir} -type d -exec ${MKDIR} "${DATADIR}/{}" \; && \
	    ${FIND} ${dir} -type f -exec ${INSTALL_DATA} "{}" "${DATADIR}/{}" \;
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/demos/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
