CATEGORIES=	japanese
MASTER_SITES=	https://github.com/skk-dev/dict/raw/4eb91a3bbfef70bde940668ec60f3beae291e971/:skkdic
PKGNAMESUFFIX=	-dict
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${SKKDIC_FILE}:skkdic
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	Dictionary for C/Migemo Japanese incremental search tool

LICENSE=	GPLv2

MASTERDIR=	${.CURDIR}/../../japanese/cmigemo
PKGDIR=		${.CURDIR}

USES=		perl5
USE_PERL5=	patch build run

ALL_TARGET=	gcc-dict
INSTALL_TARGET=	gcc-install-dict

SKKDIC_FILE=	SKK-JISYO.L
LICENSE_DISTFILES=	${SKKDIC_FILE}

post-extract:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${SKKDIC_FILE} ${WRKSRC}/dict/

.include "${MASTERDIR}/Makefile"
