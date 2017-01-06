# Created by: Hannes Hauswedell <h2+fbsdports@fsfe.org>
# $FreeBSD$

PORTNAME=	seqan-apps
PORTVERSION=	2.2.0
DISTVERSIONPREFIX=	seqan-v
PORTREVISION=	2
CATEGORIES=	biology

MAINTAINER=	h2+fbsdports@fsfe.org
COMMENT=	Official Bioinformatic applications based on the SeqAn library

LICENSE=	BSD3CLAUSE LGPL3 GPLv3
LICENSE_COMB=	multi

BUILD_DEPENDS=	boost-libs>0:devel/boost-libs

USE_GITHUB=	yes
GH_ACCOUNT=	seqan
GH_PROJECT=	seqan

# once #199603 is resolved, do the following instead of USE_GCC
# USES=		cmake:outsource compiler:openmp,c++14-lang
USES=		cmake:outsource
CMAKE_ARGS=	-DSEQAN_BUILD_SYSTEM="SEQAN_RELEASE_APPS"

USE_GCC=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1000000
post-patch:
	# missing C99 functions in FreeBSD's math.h, use C++ instead
	@${REINPLACE_CMD} -e 's|expl(|std::exp(|g' ${WRKSRC}/apps/snp_store/snp_store.h
	@${REINPLACE_CMD} -e 's|logl(|std::log(|g' ${WRKSRC}/apps/snp_store/snp_store.h
	# the other way around (use math.h instead of cmath)
	@${REINPLACE_CMD} -e 's|std::round|round|g' ${WRKSRC}/apps/yara/mapper_writer.h
	@${REINPLACE_CMD} -e 's|std::erfc|erfc|g' ${WRKSRC}/apps/yara/bits_matches.h
.endif

.if ${ARCH} == "i386"
PLIST_SUB+=	RM_I386="@comment "
.else
PLIST_SUB+=	RM_I386=""
.endif

.include <bsd.port.post.mk>
