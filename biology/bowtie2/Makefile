# Created by: Jason Bacon
# $FreeBSD$

PORTNAME=		bowtie2
PORTVERSION=		2.2.8
DISTVERSIONPREFIX=	v
CATEGORIES=		biology

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Ultrafast, memory-efficient short read aligner

LICENSE=	GPLv3

# May also work on other 64-bit platforms, but untested
ONLY_FOR_ARCHS=	amd64
USES=		gmake perl5 shebangfix
USE_PERL5=	run
SHEBANG_FILES=	scripts/*.pl

USE_GITHUB=	yes
GH_ACCOUNT=	BenLangmead

post-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/scripts
	${INSTALL_PROGRAM} \
		${WRKSRC}/bowtie2*-s \
		${WRKSRC}/bowtie2*-l \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} \
		${WRKSRC}/scripts/*.sh \
		${WRKSRC}/scripts/*.pl \
		${STAGEDIR}${DATADIR}/scripts
	cd ${WRKSRC}/example && ${COPYTREE_SHARE} \
		'index reads reference' \
		${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} \
		\* \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
