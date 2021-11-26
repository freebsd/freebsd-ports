PORTNAME=	STAR
DISTVERSION=	2.7.9a
CATEGORIES=	biology
PKGNAMEPREFIX=	rna-

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Spliced Transcripts Alignment to a Reference

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/STAR-${DISTVERSION}/LICENSE

NOT_FOR_ARCHS=	i386 powerpc
NOT_FOR_ARCHS_REASON=Needs 16+ GiB RAM for typical eukaryotic genome

LIB_DEPENDS=	libhts.so:biology/htslib

USES=		compiler:c++11-lang gmake localbase:ldflags
USE_GITHUB=	yes
GH_ACCOUNT=	alexdobin

WRKSRC_SUBDIR=	source
MAKE_FLAGS=	HTSLIB=''

PLIST_FILES=	bin/STAR

post-patch:
	${RM} -rf ${WRKSRC}/htslib
	${REINPLACE_CMD} \
		-e 's|"htslib/htslib/sam.h"|<htslib/sam.h>|g' \
		-e 's|"htslib/htslib/kstring.h"|<htslib/kstring.h>|g' \
		-e 's|"htslib/htslib/bgzf.h"|<htslib/bgzf.h>|g' \
		${WRKSRC}/BAMfunctions.cpp \
		${WRKSRC}/IncludeDefine.h \
		${WRKSRC}/STAR.cpp \
		${WRKSRC}/bamRemoveDuplicates.cpp \
		${WRKSRC}/bam_cat.c \
		${WRKSRC}/bam_cat.h \
		${WRKSRC}/signalFromBAM.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/STAR ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
