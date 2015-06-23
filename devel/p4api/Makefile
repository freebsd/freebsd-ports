# $FreeBSD$

PORTNAME=	p4api
PORTVERSION=	2014.2.978861
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.perforce.com/perforce/${P4VERSION}/bin.${PLATFORM}/:tar \
		ftp://ftp.perforce.com/perforce/${P4VERSION}/doc/manuals/p4api/:pdf

EXTRACT_SUFX=
DISTFILES=	${TAR_FILES}:tar p4api.pdf:pdf
DIST_SUBDIR=	perforce/${PORTVERSION}/bin.${PLATFORM}
DISTINFO_FILE=	${MASTERDIR}/distinfo.${PLATFORM}
EXTRACT_ONLY=	${TAR_FILES}

MAINTAINER=	gordon@FreeBSD.org
COMMENT=	Perforce API (static libraries and header files)

BROKEN=		checksum mismatch

ONLY_FOR_ARCHS=	amd64 i386

RESTRICTED=	Restricted distribution
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

P4VERSION=	r${PORTVERSION:S/^20//:C/\.[0-9]+$//}

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.pre.mk>

.include "${.CURDIR}/../p4/Makefile.inc"

TAR_FILES=	p4api.tgz

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/perforce
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/perforce
	cd ${WRKSRC}/include/p4; \
	 for i in *.h; \
	 do ${INSTALL_DATA} $${i} ${STAGEDIR}${PREFIX}/include/perforce; \
	 done
	cd ${WRKSRC}/lib; \
	 for i in lib*.a; \
	 do ${INSTALL_DATA} $${i} ${STAGEDIR}${PREFIX}/lib/perforce; \
	 done
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/p4api.pdf ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/sample; \
	 for i in *; \
	 do ${INSTALL_DATA} $${i} ${STAGEDIR}${EXAMPLESDIR}; \
	 done

.include <bsd.port.post.mk>
