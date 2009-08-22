# ex:ts=8
# Ports collection makefile for:	NaturalDocs
# Date created:			Feb 27, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	naturaldocs
PORTVERSION=	1.4
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/Stable%20Releases/${PORTVERSION}
DISTNAME=	NaturalDocs-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An extensible, multi-language source code documentation generator

USE_ZIP=	yes
USE_PERL5_RUN=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

DOCSDIR=	${PREFIX}/share/doc/NaturalDocs

do-configure:
	@${ECHO_CMD} "#!/bin/sh" > ${WRKDIR}/NaturalDocs.sh
	@${ECHO_CMD} >> ${WRKDIR}/NaturalDocs.sh
	@${ECHO_CMD} "${DATADIR}/NaturalDocs \$$@" >> ${WRKDIR}/NaturalDocs.sh

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/NaturalDocs.sh ${PREFIX}/bin/NaturalDocs
	@${MKDIR} ${SITE_PERL}/NaturalDocs
	@(cd ${WRKSRC}/Modules/NaturalDocs \
		&& ${COPYTREE_SHARE} . ${SITE_PERL}/NaturalDocs)
	@${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/NaturalDocs ${DATADIR}
.for dir in Config Info JavaScript Styles
	@${MKDIR} ${DATADIR}/${dir}
	@(cd ${WRKSRC}/${dir} && ${COPYTREE_SHARE} . ${DATADIR}/${dir})
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/Help && ${COPYTREE_SHARE} . ${DOCSDIR})
.endif

.include <bsd.port.mk>
