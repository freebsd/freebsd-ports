# New ports collection makefile for:	FreeVision
# Date created: 			8 February 2004
# Whom: 				John Merryweather Cooper
#
# $FreeBSD$
#

PORTNAME=	fv
PORTVERSION=	2.0.2
CATEGORIES=	devel lang
MASTER_SITES=	ftp://ftp.freepascal.org/pub/fpc/dist/i386-freebsd-${PORTVERSION}/ \
		ftp://planetmirror.com/pub/fpc/dist/i386-freebsd-${PORTVERSION}/ \
		ftp://ftp.jp.freepascal.org/mirror/fpc/dist/i386-freebsd-${PORTVERSION}/ \
		ftp://freepascal.stack.nl/pub/fpc/dist/i386-freebsd-${PORTVERSION}/ \
		ftp://ftp.no.freepascal.org/pub/fpc/dist/i386-freebsd-${PORTVERSION}/ \
		ftp://ftp.us.freepascal.org/pub/fpc/dist/i386-freebsd-${PORTVERSION}/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	freepascal
PKGNAMEPREFIX=	fpc-
DISTNAME=	${PKGNAMEPREFIX}${PORTVERSION}.${BUILDNAME}
EXTRACT_SUFX=	.tar

MAINTAINER=	acardenas@bsd.org.pe
COMMENT=	FreeVision is a Free Pascal unit for Delphi support

EXAMPLESDIR=	share/examples/${PKGNAMEPREFIX}${PORTVERSION}
ONLY_FOR_ARCHS=	i386
NO_BUILD=	yes

BUILDNAME=	i386-freebsd
PLIST_SUB+=	PORTVERSION=${PORTVERSION} \
		BUILDNAME=${BUILDNAME}

do-extract:
# unpack distribution
	@${MKDIR} ${WRKSRC}
	@${TAR} xf ${DISTDIR}/${DISTNAME}.tar \
		--directory ${WRKSRC}
	@${TAR} xf ${WRKSRC}/binary.${BUILDNAME}.tar \
		--directory ${WRKSRC}

# unpack binary and fv distribution
	@${MKDIR} ${WRKSRC}/${PORTNAME}
	@${TAR} zxf ${WRKSRC}/units-${PORTNAME}.${BUILDNAME}.tar.gz \
		--directory ${WRKSRC}/${PORTNAME}

do-install:
.for DIRE in lib
	@cd ${WRKSRC}/${PORTNAME}/${DIRE} && \
		${FIND} * -type d -exec ${MKDIR} "{}" "${PREFIX}/${DIRE}/{}" \; && \
			${FIND} * -type f -exec ${INSTALL_SCRIPT} "{}" "${PREFIX}/${DIRE}/{}" \;
.endfor

post-install:
.if !defined (NOPORTDOCS)
	@cd ${WRKSRC}/${PORTNAME}/share && \
		${FIND} * -type d -exec ${MKDIR} "{}" "${PREFIX}/share/{}" \; && \
			${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${PREFIX}/share/{}" \;
.endif

.include <bsd.port.mk>
