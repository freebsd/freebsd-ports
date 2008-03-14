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

BROKEN=		Does not compile

USE_GNUSTEP=	yes
USE_GNUSTEP_CONFIGURE=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_MAKE=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}
CPPFLAGS+=	-I${PREFIX}/System/Library/Headers/
CONFIGURE_ENV+=	CC=${CC} CFLAGS="${CFLAGS}" CPPFLAGS="${CPPFLAGS}" MAKE="${GMAKE}"
BASEDIR=	${WRKSRC}/nextstep/build/Emacs.app
CONFIGURE_ARGS+=	--without-gcc --with-ns --without-x --with-pop \
		--prefix=${BASEDIR}/Resources --exec-prefix=${BASEDIR} --libexecdir=${BASEDIR}/libexec \
		${CONFIGURE_TARGET}
USE_GMAKE=	yes
USE_MAKEFILE=	yes
MAKE_ENV+=	MAKE="${GMAKE}" EMACSLOADPATH="${WRKSRC}/lisp:${WRKSRC}/leim"

post-configure:
	@${REINPLACE_CMD} -e 's|#define config_machfile "m/.h"|#define config_machfile "m/sparc.h"|g' ${WRKSRC}/src/config.h

post-install:
	cd ${BASEDIR}/Resources && ${MV} -f share/emacs/*/* .
	cd ${BASEDIR}/Resources && ${RM} -fr share
	cd ${BASEDIR}/bin && ${RM} -f emacs emacs-23*
	cd ${BASEDIR}/libexec && ${MV} -f emacs/*/*/* .
	cd ${BASEDIR}/libexec && ${RM} -fr emacs
	${CP} -r ${WRKSRC}/nextstep/build/Emacs.app ${PREFIX}/System/Applications/
.if defined(PACKAGE_BUILDING) || defined(BATCH) || defined(CLEAN_ROOT)
	${RM} -rf /root/GNUstep
.endif

.include <bsd.port.mk>
