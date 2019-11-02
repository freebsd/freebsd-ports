# Created by: Patrick Li <pat@databits.net>
# $FreeBSD$

PORTNAME=	hnb
PORTVERSION=	1.9.18
DISTVERSIONPREFIX=	v
CATEGORIES=	editors

MAINTAINER=	fox@FreeBSD.org
COMMENT=	Hierarchical NoteBook a data organizer

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake

USE_GITHUB=	yes
GH_ACCOUNT=	fraggerfox

MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz
PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/hnb ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN}	${WRKSRC}/doc/hnb.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/Documentation.* ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/hnbrc ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
