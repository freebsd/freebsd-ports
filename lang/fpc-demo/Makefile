# New ports collection makefile for:	Free Pascal Examples
# Date created: 			9 February 2004
# Whom: 				John Merryweather Cooper
#
# $FreeBSD$
#

PORTNAME=	demo
PORTVERSION=	1.0.10
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.freepascal.org/pub/fpc/dist/FreeBSD/ \
		http://planetmirror.com/pub/fpc/dist/FreeBSD/ \
		ftp://ftp.jp.freepascal.org/mirror/fpc/dist/FreeBSD/ \
		ftp://freepascal.stack.nl/pub/fpc/dist/FreeBSD/ \
		ftp://ftp.no.freepascal.org/pub/fpc/dist/FreeBSD/ \
		ftp://ftp.us.freepascal.org/pub/fpc/dist/FreeBSD/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	freepascal
PKGNAMEPREFIX=	fpc-
DISTNAME=	${PKGNAMEPREFIX}${PORTVERSION}.ELF
EXTRACT_SUFX=	.tar

MAINTAINER=	coop9211@uidaho.edu
COMMENT=	Free Pascal compiler examples

EXAMPLESDIR=	${PREFIX}/share/examples/fpc
NO_BUILD=	yes

SRCDOCDIR=	${WRKSRC}/share/doc/fpc-${PORTVERSION}/demo

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 470000
EXTRACT_DEPENDS+=	gtar:${PORTSDIR}/archivers/gtar
TAR=			${LOCALBASE}/bin/gtar
.endif

do-extract:
# unpack distribution
	@${MKDIR} ${WRKSRC}
	@${TAR} xf ${DISTDIR}/${DISTNAME}.tar --directory ${WRKSRC}
# unpack docs distribution
	@${TAR} zxf ${WRKSRC}/demo.tar.gz --directory ${WRKSRC}

do-install:
	@${MKDIR} ${EXAMPLESDIR}
	cd ${SRCDOCDIR}/ && \
		${INSTALL_DATA} Makefile Makefile.fpc fpcdemos.txt \
		${EXAMPLESDIR}
	@${MKDIR} ${EXAMPLESDIR}/graph
	@${INSTALL_DATA} `${LS} ${SRCDOCDIR}/graph/*` \
		${EXAMPLESDIR}/graph
	@${MKDIR} ${EXAMPLESDIR}/linux
	@${INSTALL_DATA} `${LS} ${SRCDOCDIR}/linux/*` \
		${EXAMPLESDIR}/linux
	@${MKDIR} ${EXAMPLESDIR}/modex
	@${INSTALL_DATA} `${LS} ${SRCDOCDIR}/modex/*` \
		${EXAMPLESDIR}/modex
	@${MKDIR} ${EXAMPLESDIR}/os2
	@${INSTALL_DATA} `${LS} ${SRCDOCDIR}/os2/*` \
		${EXAMPLESDIR}/os2
	@${MKDIR} ${EXAMPLESDIR}/palmos
	@${INSTALL_DATA} `${LS} ${SRCDOCDIR}/palmos/*` \
		${EXAMPLESDIR}/palmos
	@${MKDIR} ${EXAMPLESDIR}/text
	@${INSTALL_DATA} `${LS} ${SRCDOCDIR}/text/*` \
		${EXAMPLESDIR}/text
	@${MKDIR} ${EXAMPLESDIR}/win32
	@${INSTALL_DATA} `${LS} ${SRCDOCDIR}/win32/*` \
		${EXAMPLESDIR}/win32

.include <bsd.port.post.mk>
