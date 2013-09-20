# Created by: ijliao
# $FreeBSD$

PORTNAME=	naturaldocs
PORTVERSION=	1.52
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/Stable%20Releases/${PORTVERSION}
DISTNAME=	NaturalDocs-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An extensible, multi-language source code documentation generator

USES=		perl5
USE_ZIP=	yes
USE_PERL5=	run
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

DOCSDIR=	${PREFIX}/share/doc/NaturalDocs

NO_STAGE=	yes
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
