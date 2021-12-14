PORTNAME=		bowtie
DISTVERSIONPREFIX=	v
DISTVERSION=		1.3.1
CATEGORIES=		biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Ultrafast, memory-efficient short read aligner

LICENSE=	ART10

ONLY_FOR_ARCHS=	aarch64 amd64 powerpc64 powerpc64le

# c++11-lib is just for GCC 4.2-based systems
# Remove it when support officially ends
USES=		compiler:c++11-lib gmake perl5 python:run shebangfix
USE_PERL5=	run
USE_GITHUB=	yes

SHEBANG_FILES=	scripts/*.pl bowtie bowtie-build scripts/bowtie-hbb.sh \
		bowtie-inspect
GH_ACCOUNT=	BenLangmead

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${ARCH:Mpowerpc64*} || ${ARCH:Maarch64}
MAKE_ENV=	POPCNT_CAPABILITY=0
.endif

post-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/scripts
	${INSTALL_SCRIPT} \
		${WRKSRC}/bowtie \
		${WRKSRC}/bowtie-build \
		${WRKSRC}/bowtie-inspect \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} \
		${WRKSRC}/scripts/*.sh \
		${WRKSRC}/scripts/*.pl \
		${STAGEDIR}${DATADIR}/scripts
	cd ${WRKSRC} && ${COPYTREE_SHARE} \
		'genomes indexes reads' \
		${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} \
		\* \
		${STAGEDIR}${DOCSDIR}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*-[sl]

.include <bsd.port.mk>
