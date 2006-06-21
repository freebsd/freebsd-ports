# New ports collection makefile for:	Free Pascal Compiler Docs
# Date created: 			9 February 2004
# Whom: 				John Merryweather Cooper
#
# $FreeBSD$
#

PORTNAME=	docs
PORTVERSION=	2.0.2
CATEGORIES=	lang
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
COMMENT=	Free Pascal compiler Adobe Acrobat(tm) documentation

ONLY_FOR_ARCHS=	i386
NO_BUILD=	yes

DOCSDIR=	${PREFIX}/share/doc/fpdocs-${PORTVERSION}
PORTDOCS=	chart.pdf fcl.pdf fpdoc.pdf prog.pdf ref.pdf rtl.pdf user.pdf
BUILDNAME=	i386-freebsd
PLIST_SUB+=	PORTVERSION=${PORTVERSION} \
		BUILDNAME=${BUILDNAME}
SUB_FILES=	pkg-message

do-extract:
# unpack distribution
	@${MKDIR} ${WRKSRC}
	@${TAR} xf ${DISTDIR}/${DISTNAME}.tar \
		--directory ${WRKSRC}
	@${TAR} xf ${WRKSRC}/binary.${BUILDNAME}.tar \
		--directory ${WRKSRC}

# unpack binary and docs distribution
	@${MKDIR} ${WRKSRC}/${PORTNAME}
	@${TAR} zxf ${WRKSRC}/doc-pdf.tar.gz \
		--directory ${WRKSRC}/${PORTNAME}

do-install:
	@cd ${WRKSRC}/${PORTNAME}/share && \
		${FIND} * -type d -exec ${MKDIR} "{}" "${PREFIX}/share/{}" \; && \
			${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${PREFIX}/share/{}" \;

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
