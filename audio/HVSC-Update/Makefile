# New ports collection makefile for:	HVSC-Update
# Date created:				13 October 2002
# Whom:					Anders Nordby <anders@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	HVSC-Update
PORTVERSION=	2.8.3
CATEGORIES=	audio emulators
MASTER_SITES=	http://sidplay2.sourceforge.net/ \
		ftp://ftp.nuug.no/pub/anders/distfiles/
DISTNAME=	${PORTNAME}-Tool-${PORTVERSION}-Source
EXTRACT_SUFX=	.tgz

MAINTAINER=	anders@FreeBSD.org
COMMENT=	Update program for the HVSC C= 64 SID tune collection

BUILD_DEPENDS=	imake:${X_IMAKE_PORT}

WRKSRC=	${WRKDIR}/${PORTNAME}-Tool-${PORTVERSION}-Source

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

DOCS=	HVSC_Update.txt SID_file_format.txt

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502112
BROKEN=         "Does not compile on FreeBSD >= 5.x"
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/Update ${PREFIX}/bin/HVSC-Update
.if !defined(NOPORTDOCS)
	@${INSTALL} -d -m 0755 ${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.post.mk>
