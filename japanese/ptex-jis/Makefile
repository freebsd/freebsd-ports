# New ports collection makefile for:	pTeX-jis
# Version required:	2.1.5
# Date created:		05 Oct 1997
# Whom:			max
#
# $Id: Makefile,v 1.2 1997/10/04 17:58:45 max Exp $
#

DISTNAME=	ptex215
PKGNAME=	ja-ptex-jis-2.1.5
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/ptex215/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} plib13-jis.tar.gz

MAINTAINER=	max@FreeBSD.ORG

RUN_DEPENDS=	ptex-common:${PORTSDIR}/japanese/ptex-common

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	jis
WRKSRC=		${.CURDIR}/../ptex-common/work/web2c-7.0/web2c/${DISTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
ALL_TARGET=	default

BINARIES=	iniptex jbibtex pdvitype pltotf ptex tftopl virptex

pre-extract:
.if !exists(${.CURDIR}/../ptex-common/work/.build_done)
	@(cd ${.CURDIR}/../ptex-common; \
	  ${SETENV} ${MAKE_ENV} ${MAKE})
.endif

post-extract:
	@${RM} -rf ${WRKSRC}
	@${MV} ${WRKDIR}/${DISTNAME} ${.CURDIR}/../ptex-common/work/web2c-7.0/web2c

pre-install:
	@${EXTRACT_CMD} -C ${PREFIX} -zxf ${DISTDIR}/plib13-jis.tar.gz

post-install:
.for bin in ${BINARIES}
	@strip ${PREFIX}/bin/${bin}
.endfor

pre-clean:
	@${RM} -rf ${WRKSRC}

MANUAL_PACKAGE_BUILD=	incompatible with other versions of ptex-*

.include <bsd.port.mk>
