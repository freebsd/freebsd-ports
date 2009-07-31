# New ports collection makefile for:	sunbird
# Date created:		2005-02-26
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/deskutils/sunbird/Makefile,v 1.19 2006/10/13 04:40:20 ahze Exp $
#

PORTNAME=	sunbird
PORTVERSION=	0.9
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	deskutils
MASTER_SITES=	${MASTER_SITE_MOZILLA_EXTENDED}
MASTER_SITE_SUBDIR=	calendar/sunbird/releases/${DISTVERSION}/source
DISTNAME=	lightning-${PORTNAME}-${DISTVERSION}-source

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	Redesign of the Mozilla Calendar with XUL interface

USE_AUTOTOOLS=	libtool:15
ALL_TARGET=	default
CONFIGURE_ENV=	LOCALBASE=${LOCALBASE}
HAS_CONFIGURE=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes
WANT_GNOME=	yes
WANT_PERL=	yes
SUNBIRD=	${PORTNAME}
SUNBIRD_ICON_SRC=	${PREFIX}/lib/sunbird/chrome/icons/default/default.xpm
SUNBIRD_ICON=		${PORTNAME}.xpm
LIBS=		-Wl,-Bsymbolic -lc
MOZ_PKGCONFIG_FILES=	${PORTNAME}-js ${PORTNAME}-xpcom ${PORTNAME}-plugin
PKGCONFIG_FILES=	${MOZ_PKG_CONFIG_FILES}
MOZ_OPTIONS=	--enable-application=calendar \
		--enable-system-cairo \
		--with-system-nss \
		--enable-canvas
MOZ_MK_OPTIONS=	MOZ_CO_PROJECT=calendar

GECKO_PLIST_PRE_FILES=	lib/sunbird/extensions/{972ce4c6-7e08-4474-a285-3208198ce6fd}/chrome.manifest \
			lib/sunbird/extensions/{e2fda1a4-762b-4020-b5ad-a41df1933103}/chrome.manifest

.include <bsd.init.mk>
.include <bsd.libnames.mk>
.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/mozilla/Makefile.common"

.if ${ARCH}=="sparc64"
BROKEN=		does not build
.endif

post-patch:
	@${SED} -e 's|@SUNBIRD_ICON@|${SUNBIRD_ICON}|' \
		${FILESDIR}/sunbird.desktop.in >${WRKDIR}/sunbird.desktop
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/security/manager/ssl/src/Makefile.in
	@${REINPLACE_CMD} -e 's|%%LIB_BZ2%%|${LIBBZ2}|' \
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
	${TOUCH} ${PREFIX}/lib/sunbird/extensions/{972ce4c6-7e08-4474-a285-3208198ce6fd}/chrome.manifest
	${TOUCH} ${PREFIX}/lib/sunbird/extensions/{e2fda1a4-762b-4020-b5ad-a41df1933103}/chrome.manifest

.include <bsd.port.post.mk>
