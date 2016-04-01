# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	spark
PORTVERSION=	2014
CATEGORIES=	lang
MASTER_SITES=	http://downloads.dragonlace.net/src/:main LOCAL/marino:main \
		GCC/${MS_SUBDIR}
DISTNAME=	spark-gpl-${PORTVERSION}-src
DISTFILES=	${DISTNAME}.tar.gz:main ${IDENTIFICATION}.tar.bz2
EXTRACT_ONLY=	${DISTNAME}.tar.gz

MAINTAINER=	marino@FreeBSD.org
COMMENT=	Technology for engineering high-reliability s/w applications

LICENSE=	GPLv3

BROKEN=		brutally fails test suite - with ICE
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-10-29

BUILD_DEPENDS=	gnatcoll>=2014:devel/gnatcoll
RUN_DEPENDS=	gnatwhy3:math/why3-spark \
		alt-ergo:math/alt-ergo

USES=		ada gmake
ALL_TARGET=	gnat2why gnatprove
GNATSRC=	${WRKSRC}/gnat2why/gnat_src
PORTDOCS=	html pdf

MAKE_JOBS_UNSAFE= yes

.include "${.CURDIR}/../gcc5-aux/Makefile.version"

post-extract:
	(cd ${WRKDIR} && ${TAR} -xf ${DISTDIR}/${IDENTIFICATION}.tar.bz2 \
		${IDENTIFICATION}/gcc/ada)
	${LN} -s ${WRKDIR}/${IDENTIFICATION}/gcc/ada ${GNATSRC}
	${MKDIR} ${WRKSRC}/install/bin

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/install/bin/* ${STAGEDIR}${PREFIX}/bin
	(cd ${WRKSRC}/install/share && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share)

.include <bsd.port.mk>
