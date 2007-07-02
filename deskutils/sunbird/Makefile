# New ports collection makefile for:	sunbird
# Date created:		2005-02-26
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/deskutils/sunbird/Makefile,v 1.19 2006/10/13 04:40:20 ahze Exp $
#

PORTNAME=	sunbird
PORTVERSION=	0.5
PORTEPOCH=	1
CATEGORIES=	deskutils
MASTER_SITES=	${MASTER_SITE_MOZILLA_EXTENDED}
MASTER_SITE_SUBDIR=	calendar/sunbird/releases/${DISTVERSION}/source
DISTNAME=	lightning-${PORTNAME}-${DISTVERSION}-source

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Redesign of the Mozilla Calendar with XUL interface

USE_AUTOTOOLS=	libtool:15
USE_GCC=	3.4+
ALL_TARGET=	default
CONFIGURE_ENV=	LOCALBASE=${LOCALBASE}
HAS_CONFIGURE=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes
WANT_GNOME=	yes
SUNBIRD=	${PORTNAME}
SUNBIRD_ICON_SRC=	${PREFIX}/lib/sunbird/icons/default.xpm
SUNBIRD_ICON=		${PORTNAME}.xpm
LIBS=		-Wl,-Bsymbolic -lc
MOZ_PKGCONFIG_FILES=	${PORTNAME}-js ${PORTNAME}-xpcom ${PORTNAME}-plugin
PKGCONFIG_FILES=	${MOZ_PKG_CONFIG_FILES}
MOZ_OPTIONS=	--enable-application=calendar \
		--enable-system-cairo \
		--with-system-nss \
		--enable-canvas
MOZ_MK_OPTIONS=	MOZ_CO_PROJECT=calendar

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/mozilla/Makefile.common"

.if ${OSVERSION} < 500000
BROKEN=	does not build
.endif

.if ${ARCH}=="sparc64"
IGNORE=	 does not build
.endif

.if ${PERL_LEVEL} < 500600
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-config_make-jars.pl
.endif

post-patch:
	@${SED} -e 's|@SUNBIRD_ICON@|${SUNBIRD_ICON}|' \
		${FILESDIR}/sunbird.desktop.in >${WRKDIR}/sunbird.desktop
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/security/manager/ssl/src/Makefile.in
	@${REINPLACE_CMD} -e 's|%%LIB_BZ2%%|${LIB_BZ2}|' \
		${WRKSRC}/toolkit/mozapps/update/src/updater/Makefile.in

post-build:
	@(cd ${WRKSRC}/xpfe/components/autocomplete/src && ${GMAKE})

pre-install:
	${ECHO_CMD} 'share/applications/sunbird.desktop' >> ${PLIST}
	${ECHO_CMD} 'share/pixmaps/${SUNBIRD_ICON}' >> ${PLIST}
	${ECHO_CMD} '@unexec ${RMDIR} %D/share/applications 2>/dev/null || ${TRUE}' >> ${PLIST}
	${ECHO_CMD} '@dirrmtry lib/sunbird/plugins' >> ${PLIST}
	${ECHO_CMD} '@dirrmtry lib/sunbird' >> ${PLIST}

do-install:
	${MKDIR} ${PREFIX}/share/applications ${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKDIR}/sunbird.desktop ${PREFIX}/share/applications
	${LN} -sf ${SUNBIRD_ICON_SRC} ${PREFIX}/share/pixmaps/${SUNBIRD_ICON}

.include <bsd.port.post.mk>
