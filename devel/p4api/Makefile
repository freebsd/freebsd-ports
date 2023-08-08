PORTNAME=	p4api
PORTVERSION=	${YEAR}.${MAJOR}.${MINOR}
CATEGORIES=	devel
# Perforce does not version their distfiles when they patch.
# This does not play well with FreeBSD's conventions.
MASTER_SITES=	https://ftp.perforce.com/perforce/${P4VERSION}/bin.tools/p4source${EXTRACT_SUFX}?dummy=/ \
		https://hesiod.org/distfiles/perforce-${MINOR}/p4source${EXTRACT_SUFX}?dummy=/
DISTNAME=	p4source-${MINOR}

MAINTAINER=	antonfb@hesiod.org
COMMENT=	Perforce API (static libraries and header files)
WWW=		https://www.perforce.com/products/helix-core

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${JAM}:devel/jam

USES=		tar:tgz

PATCHDIR=	${.CURDIR}/../p4/files

DISTINFO_FILE=	${.CURDIR}/../p4/distinfo

OPTIONS_DEFINE=	EXAMPLES

WRKSRC=		${WRKDIR}/p4source-${PORTVERSION}

.include <bsd.port.pre.mk>
.include "../p4/Makefile.inc"

do-build:
	cd ${WRKSRC} && ${SETENV} C++="${CXX}" C++FLAGS="${CXXFLAGS}" \
		CCFLAGS="${CFLAGS}" \
		LINKFLAGS="${LDFLAGS}" \
		OSVER=${OSVER} \
		API=1 \
		SSL="yes" \
		SSLLIB=-lssl \
		CRYPTOLIB=-lcrypto \
		TYPE=pic \
		${JAM} -dx -sUSE_EXTENSIONS=0 -j${MAKE_JOBS_NUMBER} p4api p4api.tar

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/perforce
	cd ${WRKSRC}/p4-bin/bin.pic/p4api-*/include/p4 && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/perforce
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/perforce
	cd ${WRKSRC}/p4-bin/bin.pic/p4api-*/lib && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/lib/perforce

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/p4-bin/bin.pic/p4api-*/sample && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.post.mk>
