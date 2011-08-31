# New ports collection makefile for:	HVSC-Update
# Date created:				13 October 2002
# Whom:					Anders Nordby <anders@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	HVSC-Update
PORTVERSION=	2.8.5
CATEGORIES=	audio emulators
MASTER_SITES=	http://www.hvsc.c64.org/download/files/tools/
DISTNAME=	${PORTNAME:S/-/_/}_Tool_source_${PORTVERSION:S/.//g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Update program for the HVSC C= 64 SID tune collection

BUILD_DEPENDS=	makedepend:${PORTSDIR}/devel/makedepend

WRKSRC=		${WRKDIR}/${PORTNAME:S/-/_/}_Tool_${PORTVERSION:S/.//g}

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

PORTDOCS=	HVSC_Update.txt SID_file_format.txt
PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/Update ${PREFIX}/bin/${PORTNAME}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
