# New ports collection makefile for:	pTeX-jis
# Version required:	2.1.8
# Date created:		05 Oct 1997
# Whom:			max
#
# $Id: Makefile,v 1.7 1998/12/02 05:57:05 asami Exp $
#

DISTNAME=	ptex218
PKGNAME=	ja-ptex-jis-2.1.8
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/ptex218/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} plib-1.4-jis.tar.gz \
		Makefile.in.patch.txt

MAINTAINER=	max@FreeBSD.ORG

RUN_DEPENDS=	ptex-common:${PORTSDIR}/japanese/ptex-common

MANUAL_PACKAGE_BUILD=	incompatible with other versions of ptex-*
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
DIST_SUBDIR=	ptex
CONFIGURE_ARGS=	jis
WRKSRC=	${WRKDIRPREFIX}${.CURDIR}/../ptex-common/work/web2c-7.2/web2c/${DISTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
ALL_TARGET=	default

BINARIES=	iniptex jbibtex pdvitype pltotf ptex tftopl virptex

pre-extract:
.if !exists(${WRKDIRPREFIX}${.CURDIR}/../ptex-common/work/.build_done)
	@(cd ${.CURDIR}/../ptex-common; \
	  ${SETENV} ${MAKE_ENV} ${MAKE})
.endif

post-extract:
	@${RM} -rf ${WRKSRC}
	@${MV} ${WRKDIR}/${DISTNAME} ${WRKDIRPREFIX}${.CURDIR}/../ptex-common/work/web2c-7.2/web2c

pre-patch:
	@/usr/bin/uudecode -p ${DISTDIR}/${DIST_SUBDIR}/Makefile.in.patch.txt | \
	  ${PATCH} ${PATCH_DIST_ARGS}

pre-install:
	@${TAR} -C ${PREFIX}/share -zxf ${DISTDIR}/${DIST_SUBDIR}/plib-1.4-jis.tar.gz

post-install:
.for bin in ${BINARIES}
	@strip ${PREFIX}/bin/${bin}
.endfor

pre-clean:
	@${RM} -rf ${WRKSRC}

.include <bsd.port.mk>
