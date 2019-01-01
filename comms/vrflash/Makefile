# $FreeBSD$

PORTNAME=	vrflash
PORTVERSION=	0.24
CATEGORIES=	comms
MASTER_SITES=	SF/agos/vrflash/${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Flash kernels and romdisks to the Agenda VR3

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
DOCS=		agenda-flashing-overview.txt troubleshooting.txt \
		pmon-protect-unprotect.txt usage.txt

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vrflash ${STAGEDIR}${PREFIX}/bin/
do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
