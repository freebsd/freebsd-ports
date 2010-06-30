# New ports collection makefile for:   kvirc
# Date created:        05 January 2004
# Whom:                Michael Ranner
#
# $FreeBSD$
#

PORTNAME=	kvirc
PORTVERSION=	3.4.2
PORTREVISION=	4
CATEGORIES=	irc kde
MASTER_SITES=	ftp://ftp.kvirc.de/pub/kvirc/${PORTVERSION}/source/ \
		ftp://ftp.kvirc.de/pub/%SUBDIR%/ \
		http://kvirc.gmake.de/pub/%SUBDIR%/ \
		LOCAL/beech
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTVERSION}/source

MAINTAINER=	makc@FreeBSD.org
COMMENT=	IRC client for QT and KDE

FORBIDDEN=	multiple vulnerabilities

USE_AUTOTOOLS=	libtool:22
USE_BZIP2=	yes
USE_KDELIBS_VER=3
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_GETTEXT=	yes
INSTALLS_ICONS=	yes
PLIST_SUB=		VER=${PORTVERSION}

MAN1=	kvirc.1

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

.include <bsd.port.post.mk>
