# New ports collection makefile for:    emacs.app
# Date created:         4 Sep 2006
# Whom:                 gurkan@phys.ethz.ch
#
# $FreeBSD$
#

PORTNAME=	emacs.app
PORTVERSION=	9.0
PORTREVISION=	3
CATEGORIES=	editors gnustep
MASTER_SITES=	SF/emacs-app/emacs-app/${PORTVERSION}-pre3
DISTNAME=	emacs-23.0.0_NS-${PORTVERSION}pre3b

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	The GNU Emacs editor on GNUstep

LICENSE=	GPLv2

USE_GNUSTEP=	yes
USE_GNUSTEP_CONFIGURE=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_MAKE=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}
CPPFLAGS+=	-I${GNUSTEP_SYSTEM_ROOT}/Library/Headers
CFLAGS+=	-I${GNUSTEP_SYSTEM_ROOT}/Library/Headers
LDFLAGS+=	-L${GNUSTEP_SYSTEM_ROOT}/Library/Libraries
CONFIGURE_ENV+=	CC=${CC} CFLAGS="${CFLAGS}" CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}" MAKE="${GMAKE}"
CONFIGURE_ENV+=	GNUSTEP_SYSTEM_HEADERS="${GNUSTEP_SYSTEM_ROOT}/Library/Headers"
BASEDIR=	${WRKSRC}/nextstep/build/Emacs.app
CONFIGURE_ARGS+=	--without-gcc --with-ns --without-x --with-pop \
		--prefix=${BASEDIR}/Resources --exec-prefix=${BASEDIR} --libexecdir=${BASEDIR}/libexec \
		${CONFIGURE_TARGET}
USE_GMAKE=	yes
USE_MAKEFILE=	yes
MAKE_ENV+=	MAKE="${GMAKE}" EMACSLOADPATH="${WRKSRC}/lisp:${WRKSRC}/leim"
MAKE_ENV+=	GNUSTEP_SYSTEM_HEADERS="${GNUSTEP_SYSTEM_ROOT}/Library/Headers"

post-configure:
	@${REINPLACE_CMD} -e 's|#define config_machfile "m/.h"|#define config_machfile "m/sparc.h"|g' ${WRKSRC}/src/config.h

post-install:
	cd ${BASEDIR}/Resources && ${MV} -f share/emacs/*/* .
	cd ${BASEDIR}/Resources && ${RM} -fr share
	cd ${BASEDIR}/bin && ${RM} -f emacs emacs-23*
	cd ${BASEDIR}/libexec && ${MV} -f emacs/*/*/* .
	cd ${BASEDIR}/libexec && ${RM} -fr emacs
	${CP} -r ${WRKSRC}/nextstep/build/Emacs.app ${GNUSTEP_PREFIX}/System/Applications/
.if defined(PACKAGE_BUILDING) || defined(BATCH) || defined(CLEAN_ROOT)
	${RM} -rf /root/GNUstep
.endif

.include <bsd.port.mk>
