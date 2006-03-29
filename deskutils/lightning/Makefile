# New ports collection makefile for:	sunbird
# Date created:		2005-02-26
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/deskutils/sunbird/Makefile,v 1.13 2005/11/23 04:54:57 ahze Exp $
#

PORTNAME=	sunbird
PORTVERSION=	0.3a1
PORTREVISION=	2
CATEGORIES=	deskutils
MASTER_SITES=	${MASTER_SITE_MOZILLA}
MASTER_SITE_SUBDIR=	sunbird/new-directory/releases/${DISTVERSION}/source
DISTNAME=	${PORTNAME}-${DISTVERSION}-source

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Redesign of the Mozilla Calendar with XUL interface

USE_GCC=	3.4+
ALL_TARGET=	default
CONFIGURE_ENV=	LOCALBASE=${LOCALBASE}
HAS_CONFIGURE=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes
WANT_GNOME=	yes
USE_X_PREFIX=	yes
SUNBIRD=	${PORTNAME}
SUNBIRD_ICON_SRC=	${PREFIX}/lib/sunbird/icons/default.xpm
SUNBIRD_ICON=		${PORTNAME}.xpm

MOZ_PROTOCOLS=	about,http,ftp,file,jar,res
MOZ_OPTIONS=	--enable-application=calendar \
		--enable-plaintext-editor-only \
		--disable-plugins --disable-cookies
MOZ_MK_OPTIONS=	MOZ_CO_PROJECT=calendar

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../www/mozilla/Makefile.common"

.if ${OSVERSION} < 500000
BROKEN=	does not build
.endif

.if ${PERL_LEVEL} < 500600
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-config_make-jars.pl
.endif

post-extract::
	@${SED} -e 's|@SUNBIRD_ICON@|${SUNBIRD_ICON}|' \
		${FILESDIR}/sunbird.desktop.in >${WRKDIR}/sunbird.desktop

post-patch:
.for ii in modules/libpref/src/init extensions/sroaming/resources/content/prefs \
		embedding/minimo
	@${REINPLACE_CMD} -e '/accessibility.typeaheadfind.enablesound/s/true/false/ ; \
		/dom.disable_window_open_feature.toolbar/s/false/true/' \
		${WRKSRC}/${ii}/all.js
.endfor

pre-install:
	${ECHO_CMD} 'share/applications/sunbird.desktop' >> ${PLIST}
	${ECHO_CMD} 'share/pixmaps/${SUNBIRD_ICON}' >> ${PLIST}
	${ECHO_CMD} '@unexec ${RMDIR} %D/share/applications 2>/dev/null || ${TRUE}' >> ${PLIST}

do-install:
	${MKDIR} ${PREFIX}/share/applications ${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKDIR}/sunbird.desktop ${PREFIX}/share/applications
	${LN} -sf ${SUNBIRD_ICON_SRC} ${PREFIX}/share/pixmaps/${SUNBIRD_ICON}

.include <bsd.port.post.mk>
