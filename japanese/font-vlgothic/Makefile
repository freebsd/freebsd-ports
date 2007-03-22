# New ports collection makefile for:	VLGothic fotns
# Date created:		31 Oct 2006
# Whom:			NIIMI Satoshi <sa2c@sa2c.net>
#
# $FreeBSD$
#

PORTNAME=	vlgothic
PORTVERSION=	20070317
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	http://vinelinux.org/~daisuke/vlgothic/ \
		http://dicey.org/vlgothic/
DISTNAME=	VLGothic-${PORTVERSION}

MAINTAINER=	sa2c@sa2c.net
COMMENT=	Free Japanese TrueType fonts named 'VLGothic'

BUILD_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig
RUN_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig

USE_X_PREFIX=	yes
USE_BZIP2=	yes
NO_BUILD=	yes

FONTSDIR=	lib/X11/fonts/vlgothic
PLIST_SUB=	FONTSDIR=${FONTSDIR}

WRKSRC=		${WRKDIR}/VLGothic

DOC_FILES=	Changelog LICENSE LICENSE.en LICENSE_E.mplus LICENSE_J.mplus \
		README README.sazanami README_J.mplus

do-install:
	${MKDIR} ${PREFIX}/${FONTSDIR}
	${INSTALL_DATA}	${WRKSRC}/VL-PGothic-Regular.ttf \
			${WRKSRC}/VL-Gothic-Regular.ttf \
			${PREFIX}/${FONTSDIR}
	${MKDIR} ${PREFIX}/etc/fonts/conf.d
	${INSTALL_DATA} ${FILESDIR}/63-vlgothic.conf \
			${PREFIX}/etc/fonts/conf.d
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA}	${DOC_FILES:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

post-install:
	${X11BASE}/bin/fc-cache -f -v ${PREFIX}/${FONTSDIR}

.include <bsd.port.mk>
