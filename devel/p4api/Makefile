# New ports collection makefile for:	p4api
# Date created:				27 Mar 2003
# Whom:					kuriyama@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	p4api
PORTVERSION=	${VERSION}
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.perforce.com/pub/perforce/r${PORTVERSION}/bin.${PLATFORM}${PLATFORM_SUFX}/:tar \
		http://www.perforce.com/perforce/doc.${DOCVER}/manuals/p4api/:pdf

EXTRACT_SUFX=
DISTFILES=	${TAR_FILES}:tar p4api.pdf:pdf
DIST_SUBDIR=	perforce/${VERSION}/${ARCH}-${PLATFORM}
EXTRACT_ONLY=	${TAR_FILES}

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perforce API (static libraries and header files)

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/p4api-2008.1.158777

PLATFORM=	freebsd60
VERSION=	08.1

.include <bsd.port.pre.mk>

.if ${ARCH} == i386
PLATFORM_SUFX=	x86
.elif ${ARCH} == amd64
PLATFORM_SUFX=	x86_64
.else
IGNORE=		"Unsupported platform, sorry."
.endif

TAR_FILES=	p4api.tgz

DOCVER=		${VERSION:S/.//}

do-install:
	${MKDIR} ${PREFIX}/include/perforce
	${MKDIR} ${PREFIX}/lib/perforce
	cd ${WRKSRC}/include/p4; \
	 for i in *.h; \
	 do ${INSTALL_DATA} $${i} ${PREFIX}/include/perforce; \
	 done
	cd ${WRKSRC}/lib; \
	 for i in lib*.a; \
	 do ${INSTALL_DATA} $${i} ${PREFIX}/lib/perforce; \
	 done
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/p4api.pdf ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/sample; \
	 for i in *; \
	 do ${INSTALL_DATA} $${i} ${EXAMPLESDIR}; \
	 done
.endif

.include <bsd.port.post.mk>
