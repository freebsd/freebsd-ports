# $FreeBSD$

PORTNAME=		bowtie
DISTVERSIONPREFIX=	v
DISTVERSION=		1.1.2
PORTREVISION=		8
CATEGORIES=		biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Ultrafast, memory-efficient short read aligner

LICENSE=	ART10

# May also work on other 64-bit platforms, but untested
ONLY_FOR_ARCHS=	amd64

# FIXME: bowtie-align intermittently dumps core when compiled with clang
# GCC 4.2 does not provide good performance
USES=		gmake perl5 python:run shebangfix
USE_GCC=	yes
USE_PERL5=	run
USE_GITHUB=	yes

SHEBANG_FILES=	scripts/*.pl bowtie bowtie-build bowtie-inspect
GH_ACCOUNT=	BenLangmead

OPTIONS_DEFINE=	DOCS

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
