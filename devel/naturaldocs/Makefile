# Created by: ijliao
# $FreeBSD$

PORTNAME=	naturaldocs
PORTVERSION=	1.52
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/Stable%20Releases/${PORTVERSION}
DISTNAME=	NaturalDocs-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extensible, multi-language source code documentation generator

USES=		perl5 shebangfix zip
SHEBANG_FILES=	NaturalDocs
USE_PERL5=	run
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

DOCSDIR=	${PREFIX}/share/doc/NaturalDocs

OPTIONS_DEFINE=	DOCS

do-configure:
	@${ECHO_CMD} "#!/bin/sh" > ${WRKDIR}/NaturalDocs.sh
	@${ECHO_CMD} >> ${WRKDIR}/NaturalDocs.sh
	@${ECHO_CMD} "${DATADIR}/NaturalDocs \$$@" >> ${WRKDIR}/NaturalDocs.sh

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/NaturalDocs.sh \
		${STAGEDIR}${PREFIX}/bin/NaturalDocs
	@${MKDIR} ${STAGEDIR}${SITE_PERL}/NaturalDocs
	(cd ${WRKSRC}/Modules/NaturalDocs \
		&& ${COPYTREE_SHARE} . ${STAGEDIR}${SITE_PERL}/NaturalDocs)
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/NaturalDocs ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "Config Info JavaScript Styles" \
		${STAGEDIR}${DATADIR})
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/Help && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
