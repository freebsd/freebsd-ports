# Created by: Anders Nordby <anders@FreeBSD.org>
# $FreeBSD$

PORTNAME=	HVSC-Update
PORTVERSION=	2.8.6
CATEGORIES=	audio emulators
MASTER_SITES=	http://www.hvsc.c64.org/download/files/tools/
DISTNAME=	${PORTNAME:S/-/_/}_Tool_${PORTVERSION:S/.//g}_source

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Update program for the HVSC C= 64 SID tune collection

BUILD_DEPENDS=	makedepend:${PORTSDIR}/devel/makedepend

GNU_CONFIGURE=	yes
USES=		gmake
WRKSRC=		${WRKDIR}/${PORTNAME:S/-/_/}_Tool_${PORTVERSION:S/.//g}

PORTDOCS=	HVS_file_format.txt HVSC_Update.txt SID_file_format.txt
PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/Update ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
