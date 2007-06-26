# New ports collection makefile for:    emacs.app
# Date created:         4 Sep 2006
# Whom:                 gurkan@linuks.mine.nu
#
# $FreeBSD$
#

PORTNAME=	emacs.app
PORTVERSION=	9.0
PORTREVISION=	1
CATEGORIES=	editors gnustep
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	emacs-app
DISTNAME=	emacs-23.0.0_NS-${PORTVERSION}pre3b

MAINTAINER=	gurkan@linuks.mine.nu
COMMENT=	The GNU Emacs editor on GNUstep

USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_MAKE=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}
BASEDIR=${WRKSRC}/build/Emacs.app
BINDIR=${BASEDIR}
CFLAGS+=-I${PREFIX}/System/Library/Headers/

post-configure:
	@${REINPLACE_CMD} -e 's|#define config_machfile "m/.h"|#define config_machfile "m/sparc.h"|g' ${WRKSRC}/src/config.h
	@${REINPLACE_CMD} -e's|source /etc/GNUstep/GNUstep.conf|. ${GNUSTEP_MAKEFILES}/GNUstep.sh|g' ${WRKSRC}/nextstep/compile

do-build:
	(. ${GNUSTEP_MAKEFILES}/GNUstep.sh; cd ${WRKSRC}/nextstep; ${MAKE_ENV} ./compile)

do-install:
	${CP} -r ${WRKSRC}/nextstep/build/Emacs.app ${PREFIX}/System/Applications/
.if defined(PACKAGE_BUILDING) || defined(BATCH) || defined(CLEAN_ROOT)
	${RM} -rf /root/GNUstep
.endif

.include <bsd.port.mk>
