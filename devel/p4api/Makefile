# New ports collection makefile for:	p4api
# Date created:				27 Mar 2003
# Whom:					kuriyama@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	p4api
PORTVERSION=	${VERSION}
PORTREVISION=	${REVISION}
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.perforce.com/pub/perforce/r${PORTVERSION}/bin.${PLATFORM}/:tar \
		http://www.perforce.com/perforce/doc.${DOCVER}/user/:txt
EXTRACT_SUFX=
DISTFILES=	${TAR_FILES}:tar p4api.txt:txt
DIST_SUBDIR=	perforce/${VERSION}/${ARCH}
EXTRACT_ONLY=	${TAR_FILES}

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perforce API (static libraries and header files)

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == i386
PLATFORM=	freebsd4
TAR_FILES=	p4api.tar
.else
IGNORE=		"Unsupported platform, sorry."
.endif

VERSION=	03.1
REVISION=	0
DOCVER=		${VERSION:S/.//}

do-install:
	${MKDIR} ${PREFIX}/include/perforce
	${MKDIR} ${PREFIX}/lib/perforce
	cd ${WRKSRC}; \
	 for i in *.h; \
	 do ${INSTALL_DATA} $${i} ${PREFIX}/include/perforce; \
	 done
	cd ${WRKSRC}; \
	 for i in lib*.a; \
	 do ${INSTALL_DATA} $${i} ${PREFIX}/lib/perforce; \
	 done
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/p4api.txt ${PREFIX}/include/perforce

.include <bsd.port.post.mk>
