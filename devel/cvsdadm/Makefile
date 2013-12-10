# Created by: Serge Gagnon <serge.gagnon.1@ulaval.ca>
# $FreeBSD$

PORTNAME=	cvsdadm
PORTVERSION=	0.3.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://quenix2.dyndns.org/FreeBSD/ports/distfiles/ \
    		${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool for CVSd pserver user administration

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		shebangfix perl5
NO_BUILD=	yes
USE_PERL5=	run
POD2TEXT?=	pod2text
PORTDOCS=	cvsdadm.README

SHEBANG_FILES=	cvsdadm

PLIST_FILES=	bin/cvsdadm \
		man/man1/cvsdadm.1.gz

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${POD2TEXT} ${WRKSRC}/cvsdadm > ${WRKSRC}/${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/cvsdadm ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/cvsdadm.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
