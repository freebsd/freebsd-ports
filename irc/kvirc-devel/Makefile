# New ports collection makefile for:   kvirc
# Date created:        05 January 2004
# Whom:                Michael Ranner
#
# $FreeBSD$
#

PORTNAME=	kvirc
DISTVERSION=	4.0rc1
CATEGORIES=	irc kde
MASTER_SITES=	ftp://ftp.kvirc.de/pub/kvirc/snapshots/source/ \
		http://distfiles.officialunix.com/
PKGNAMESUFFIX=	-devel

MAINTAINER=	chris@officialunix.com
COMMENT=	IRC client for QT4 and KDE4

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_PERL5=	yes
USE_QT_VER=	4
QT_COMPONENTS=	moc_build qmake_build rcc_build uic_build \
		dbus webkit gui network sql xml
USE_CMAKE=	yes
CMAKE_ARGS=	-DWITHOUT_ESD=yes -DWITHOUT_DOXYGEN=yes
INSTALLS_ICONS=	yes
CONFLICTS=	kvirc-3.4.*

MAN1=	kvirc.1
MANLANG=	"" de.ISO8859-1 de.UTF-8 it.ISO8859-1 it.UTF-8

OPTIONS=	AUDIOFILE "Compile with libaudiofile dependency" on \
			DEBUG "Compile with debug support" off \
			GSM "Compile with gsm support" off \
			KDE4 "Compile with KDE4 support (broken)" off \
			PHONON "Compile with phonon support" on

.include <bsd.port.pre.mk>

.if defined(WITH_AUDIOFILE)
LIB_DEPENDS+=	audiofile.0:${PORTSDIR}/audio/libaudiofile
.else
CMAKE_ARGS+=	-DWITHOUT_AUDIOFILE=yes
.endif

.if defined(WITH_DEBUG)
CMAKE_ARGS+=	-DDEBUG=yes -DVERBOSE=yes
.endif

.if defined(WITH_GSM)
LIB_DEPENDS+=	gsm.1:${PORTSDIR}/audio/gsm
.else
CMAKE_ARGS+=	-DWITHOUT_GSM=yes
.endif

.if defined(WITH_KDE4)
USE_KDE4+=	kdelibs kdeprefix
CMAKE_ARGS+=	-DWITH_KDE4=yes
.endif

.if defined(WITH_PHONON)
QT_COMPONENTS+=	phonon
CMAKE_ARGS+=	-DKDE4_LIB_INSTALL_DIR=${KDE4_PREFIX}/lib \
			-DKDE4_INCLUDE_INSTALL_DIR=${KDE4_PREFIX}/include
.else
CMAKE_ARGS+=	-DWITHOUT_PHONON=yes
.endif

post-configure:
	@${MV} ${WRKSRC}/data/protocols/irc.protocol ${WRKSRC}/data/protocols/kvirc.protocol
	@${MV} ${WRKSRC}/data/protocols/irc6.protocol ${WRKSRC}/data/protocols/kvirc6.protocol

.include <bsd.port.post.mk>
