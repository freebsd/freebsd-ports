# New ports collection makefile for:	gxditview (part of ja-groff)
# Date created:		14 April 1995
# Whom:			Nobuhiro Yasutomi <nobu@psrc.isac.co.jp>
#
# $FreeBSD$
#

PORTNAME=	gxditview
PORTVERSION=	1.17
CATEGORIES=	japanese print
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	groff
DISTNAME=	groff-${PORTVERSION}

PATCH_SITES=	${MASTER_SITE_LOCAL}
PATCH_SITE_SUBDIR=	okazaki/groff
PATCHFILES=	${DISTNAME}-jgroff-0.0.1.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	okazaki@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/bin/groff:${PORTSDIR}/japanese/groff

USE_AUTOCONF=	yes
USE_GMAKE=	yes
USE_IMAKE=	yes

CONFIGURE_ARGS=	--program-prefix=g --enable-nippon
CONFIGURE_ENV=	INSTALL_MAN="${INSTALL_MAN}"

MAKE_ENV=	GROFF_PREFIX=${LOCALBASE} NIPPONDEFINES="-DNIPPON"
BUILD_WRKSRC=	${WRKDIR}/${DISTNAME}/src/xditview
INSTALL_WRKSRC=	${WRKDIR}/${DISTNAME}/src/xditview

MAN1=		gxditview.1

post-extract:
	${CP} ${FILESDIR}/Imakefile ${WRKSRC}

.include <bsd.port.mk>
