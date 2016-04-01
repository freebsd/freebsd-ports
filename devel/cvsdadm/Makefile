# Created by: Serge Gagnon <serge.gagnon.1@ulaval.ca>
# $FreeBSD$

PORTNAME=	cvsdadm
PORTVERSION=	0.3.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://quenix2.dyndns.org/FreeBSD/ports/distfiles/ \
		SAVANNAH

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool for CVSd pserver user administration

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		shebangfix perl5
NO_BUILD=	yes
NO_ARCH=	yes
USE_PERL5=	run
POD2TEXT?=	pod2text
PORTDOCS=	cvsdadm.README

SHEBANG_FILES=	cvsdadm

PLIST_FILES=	bin/cvsdadm \
		man/man1/cvsdadm.1.gz

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cvsdadm ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/cvsdadm.1 ${STAGEDIR}${MANPREFIX}/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${POD2TEXT} ${WRKSRC}/cvsdadm > ${WRKSRC}/${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
