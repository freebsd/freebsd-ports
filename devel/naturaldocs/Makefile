# Created by: ijliao
# $FreeBSD$

PORTNAME=	naturaldocs
PORTVERSION=	1.52
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/Stable%20Releases/${PORTVERSION}
DISTNAME=	NaturalDocs-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extensible, multi-language source code documentation generator

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/License.txt

USES=		perl5 shebangfix zip
SHEBANG_FILES=	NaturalDocs
USE_PERL5=	run
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
NO_ARCH=	yes

DOCSDIR=	${PREFIX}/share/doc/NaturalDocs

OPTIONS_DEFINE=	DOCS

do-configure:
	@${ECHO_CMD} "#!/bin/sh" > ${WRKDIR}/NaturalDocs.sh
	@${ECHO_CMD} >> ${WRKDIR}/NaturalDocs.sh
	@${ECHO_CMD} "${DATADIR}/NaturalDocs \$$@" >> ${WRKDIR}/NaturalDocs.sh

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/NaturalDocs.sh \
		${STAGEDIR}${PREFIX}/bin/NaturalDocs
	@${MKDIR} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/NaturalDocs
	@(cd ${WRKSRC}/Modules/NaturalDocs \
		&& ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/NaturalDocs)
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/NaturalDocs ${STAGEDIR}${DATADIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "Config Info JavaScript Styles" \
		${STAGEDIR}${DATADIR})

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC}/Help && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
