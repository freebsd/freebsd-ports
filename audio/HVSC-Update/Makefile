# Created by: Anders Nordby <anders@FreeBSD.org>
# $FreeBSD$

PORTNAME=	HVSC-Update
PORTVERSION=	2.8.7
CATEGORIES=	audio emulators
MASTER_SITES=	http://www.hvsc.c64.org/download/files/tools/
DISTNAME=	${PORTNAME:S/-/_/}_Tool_source_${PORTVERSION:S/.//g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Update program for the HVSC C= 64 SID tune collection

BUILD_DEPENDS=	makedepend:devel/makedepend

GNU_CONFIGURE=	yes
USES=		gmake
WRKSRC=		${WRKDIR}/${PORTNAME:S/-/_/}_Tool_${PORTVERSION:S/.//g}

PORTDOCS=	HVS_file_format.txt HVSC_Update.txt SID_file_format.txt
PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/Update ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
