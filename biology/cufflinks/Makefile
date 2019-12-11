# $FreeBSD$

PORTNAME=	cufflinks
DISTVERSIONPREFIX=	v
DISTVERSION=	2.2.1-83
DISTVERSIONSUFFIX=	-gb4fa050
PORTREVISION=	2
CATEGORIES=	biology

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Cufflinks assembles transcripts, estimates their abundance, etc

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libhts.so:biology/htslib

USES=		autoreconf eigen:3 gmake python shebangfix
SHEBANG_FILES=	src/cuffmerge
GNU_CONFIGURE=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	cole-trapnell-lab

CXXFLAGS+=	-I${LOCALBASE}/include/eigen3
CFLAGS+=	-I${LOCALBASE}/include/eigen3 # https://github.com/cole-trapnell-lab/cufflinks/issues/113

PLIST_FILES=	bin/compress_gtf \
		bin/cuffcompare \
		bin/cuffdiff \
		bin/cufflinks \
		bin/cuffmerge \
		bin/cuffnorm \
		bin/cuffquant \
		bin/gffread \
		bin/gtf_to_sam

post-patch: # https://github.com/cole-trapnell-lab/cufflinks/issues/116
	@${GREP} -rl 'fabs(' ${WRKSRC} | ${GREP} "\.cpp$$" | ${XARGS} ${REINPLACE_CMD} 's|std::fabs(|fabs(| ; s|fabs(|::fabs(|'

.include <bsd.port.mk>
