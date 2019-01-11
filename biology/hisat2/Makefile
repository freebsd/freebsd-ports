# $FreeBSD$

PORTNAME=		hisat2
DISTVERSION=		2.1.0-23
DISTVERSIONSUFFIX=	-g20f333e
CATEGORIES=		biology perl5 python

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Alignment program for mapping next-generation sequencing reads

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

# May work on other 64-bit archs, untested
ONLY_FOR_ARCHS=		amd64
ONLY_FOR_ARCHS_REASON=	64-bit code, some assembly language

USES=		gmake perl5 python shebangfix
USE_GITHUB=	yes

SHEBANG_FILES=	hisat2 hisat2-build hisat2-inspect *.py \
		scripts/*.sh scripts/*.pl \
		hisatgenotype_modules/*.py \
		hisatgenotype_scripts/*.py \
		hisatgenotype_scripts/*.sh
GH_ACCOUNT=	infphilo

MAKEFILE=	${FILESDIR}/Makefile.pkg

.include <bsd.port.mk>
