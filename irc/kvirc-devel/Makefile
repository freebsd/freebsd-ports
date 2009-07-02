# New ports collection makefile for:   kvirc
# Date created:        05 January 2004
# Whom:                Michael Ranner
#
# $FreeBSD$
#

PORTNAME=	kvirc
PORTVERSION=	3.2.6
PORTREVISION=	2
CATEGORIES=	irc kde
MASTER_SITES=	ftp://ftp.kvirc.ru/pub/source/dev/
PKGNAMESUFFIX=	-devel

MAINTAINER=	a.pirko@inode.at
COMMENT=	IRC client for QT and KDE

USE_AUTOTOOLS=	libtool:15
USE_LDCONFIG=	yes
USE_GETTEXT=	yes
INSTALLS_ICONS=	yes
USE_BZIP2=	yes
USE_KDELIBS_VER=3
USE_GMAKE=	yes
CONFIGURE_ENV=	QTDIR="${LOCALBASE}"
PLIST_SUB=	VER=${PORTVERSION}
CONFLICTS=	kvirc-3.2.0*

MAN1=	kvirc.1

BUILD_DEPENDS+=	recode:${PORTSDIR}/converters/recode

OPTIONS=	ARTS "Compile with arts support" on \
			AUDIOFILE "Compile with libaudiofile support" on \
			ESOUND "Compile with esound support" off \
			GSM "Compile with gsm support" off

.include <bsd.port.pre.mk>

.if defined(WITH_ARTS)
LIB_DEPENDS+=		artsc.0:${PORTSDIR}/audio/arts
.else
CONFIGURE_ARGS+=	--without-arts-support
.endif

.if defined(WITH_AUDIOFILE)
LIB_DEPENDS+=		audiofile.0:${PORTSDIR}/audio/libaudiofile
.else
CONFIGURE_ARGS+=	--without-af-support
.endif

.if defined(WITH_ESOUND)
LIB_DEPENDS+=		esd.2:${PORTSDIR}/audio/esound
.else
CONFIGURE_ARGS+=	--without-esd-support
.endif

.if defined(WITH_GSM)
LIB_DEPENDS+=		gsm.1:${PORTSDIR}/audio/gsm
.else
CONFIGURE_ARGS+=	--without-gsm
.endif

post-patch:
	${REINPLACE_CMD} -e "s,-lpthread,${PTHREAD_LIBS},g" \
		-e "s,.SS_KDE_GENERAL_DIR/share/icons,${PREFIX}/share/icons," \
		-e "s,.SS_KDE_GENERAL_DIR/share/applnk,${PREFIX}/share/applnk," \
		-e "s,.SS_KDE_GENERAL_DIR/share/mimelnk,${PREFIX}/share/mimelnk," \
		-e "s,kdeservicesdir=\".SS_KDE_SERVICESDIR\",kdeservicesdir=\"${PREFIX}/share/services\"," \
		-e "s,%%LTMAIN%%,${LTMAIN}," \
		${WRKSRC}/configure
post-configure:
	@${MV} ${WRKSRC}/data/protocols/irc.protocol ${WRKSRC}/data/protocols/kvirc.protocol
	@${MV} ${WRKSRC}/data/protocols/irc6.protocol ${WRKSRC}/data/protocols/kvirc6.protocol
	${LOCALBASE}/bin/recode -f ibmpc..latin1 `find ${WRKSRC} -name "*.cpp" -print`

.include <bsd.port.post.mk>
