# $FreeBSD$

PORTNAME=	p4api
PORTVERSION=	${YEAR}.${MAJOR}.${MINOR}
PORTREVISION=	1
CATEGORIES=	devel
# Perforce stupidly rerolls their distfiles on a regular basis, updating the
# files' timestamps when they do, which changes the zip file's checksum.  Work
# around that by cacheing the distfile in LOCAL and using that version to make
# distinfo
MASTER_SITES=	LOCAL/asomers/perforce/p4:zip \
		ftp://ftp.perforce.com/perforce/${P4VERSION}/doc/manuals/p4api/:pdf \
		https://swarm.workshop.perforce.com/projects/perforce_software-p4/archives/:zip
DIST_SUBDIR=	perforce/p4
DISTNAME=	${YEAR}-${MAJOR}
DISTFILES=	${ZIP_FILES}:zip p4api.pdf:pdf
EXTRACT_ONLY=	${ZIP_FILES}

MAINTAINER=	asomers@FreeBSD.org
COMMENT=	Perforce API (static libraries and header files)

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_FreeBSD_11_powerpc64=	fails to build: /bin/sh: clang++: not found
BROKEN_FreeBSD_12_powerpc64=	fails to build: /bin/sh: clang++: not found

BUILD_DEPENDS=	${JAM}:devel/jam

OPTIONS_DEFINE=	DOCS EXAMPLES

USES=		zip

WRKSRC=		${WRKDIR}/${DISTNAME}

.include <bsd.port.pre.mk>
.include "../p4/Makefile.inc"

# Sadly, Jam always returns 1 even on success.  Ignore its return value and
# detect build errors during the install phase.
do-build:
	cd ${WRKSRC} && ${SETENV} C++="${CXX}" C++FLAGS="${CXXFLAGS}" \
		CCFLAGS="${CFLAGS}" \
		LINKFLAGS="${LDFLAGS}" \
		OSVER=${OSVER} \
		API=1 \
		TYPE=pic \
		${JAM} -dx -j${MAKE_JOBS_NUMBER} || true

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/perforce
	cd ${WRKSRC}/p4-bin/bin.pic/p4api-*/include/p4 && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/perforce
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/perforce
	cd ${WRKSRC}/p4-bin/bin.pic/p4api-*/lib && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/lib/perforce

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/p4api.pdf ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/p4-bin/bin.pic/p4api-*/sample && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.post.mk>
