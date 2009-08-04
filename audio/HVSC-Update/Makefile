# New ports collection makefile for:	HVSC-Update
# Date created:				13 October 2002
# Whom:					Anders Nordby <anders@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	HVSC-Update
PORTVERSION=	2.8.4
CATEGORIES=	audio emulators
MASTER_SITES=	http://www.hvsc.c64.org/Downloads/ \
		ftp://ftp.nuug.no/pub/anders/distfiles/
DISTNAME=	${PORTNAME:S/-/_/}_Tool_source_${PORTVERSION:S/.//g}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Update program for the HVSC C= 64 SID tune collection

BUILD_DEPENDS=	imake:${PORTSDIR}/devel/imake

WRKSRC=	${WRKDIR}/${PORTNAME:S/-/_/}_Tool_${PORTVERSION:S/.//g}

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

DOCS=	HVSC_Update.txt SID_file_format.txt

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/Update ${PREFIX}/bin/HVSC-Update
.if !defined(NOPORTDOCS)
	@${INSTALL} -d -m 0755 ${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.post.mk>
