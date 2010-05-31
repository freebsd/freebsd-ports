# New ports collection makefile for:	ibus-anthy
# Date created:				30 Apr 2009
# Whom:					Daichi GOTO <daichi@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	ibus-anthy
PORTVERSION=	1.2.1
PORTREVISION=	1
CATEGORIES=	japanese
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	daichi@freebsd.org
COMMENT=	Anthy engine for IBus

BUILD_DEPENDS=	swig:${PORTSDIR}/devel/swig13
LIB_DEPENDS=	anthy.1:${PORTSDIR}/japanese/anthy
RUN_DEPENDS=	ibus-daemon:${PORTSDIR}/textproc/ibus

USE_GNOME=	pygtk2
USE_PYTHON=	yes

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

PROJECTHOST=	ibus

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

REPLACE_FILES=	engine/engine.py setup/anthyprefs.py setup/main.py

post-patch:
	@for FILE in ${REPLACE_FILES}; do \
	    ${SED} -i .bak -e "s/@@LOCALBASE@@/${LOCALBASE:S/\//\\\//g}/g" \
	    ${WRKSRC}/$${FILE}; \
	done;

port-build:
.if !defined(WITHOUT_NLS)
	@cd ${WRKSRC}/po; \
	    ${GMAKE} all-yes
.endif

post-install:
.if !defined(WITHOUT_NLS)
	@cd ${WRKSRC}/po; \
	    ${GMAKE} install-data-yes
	@${CHMOD} 444 \
	    ${LOCALBASE}/share/locale/fr/LC_MESSAGES/ibus-anthy.mo \
	    ${LOCALBASE}/share/locale/ja/LC_MESSAGES/ibus-anthy.mo \
	    ${LOCALBASE}/share/locale/zh_CN/LC_MESSAGES/ibus-anthy.mo

.endif
	@${CAT} ${PKGMESSAGE}
	@${ECHO} To display this message again, type ${PKG_INFO} -D ${PKGNAME}

.include <bsd.port.mk>
