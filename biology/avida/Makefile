# New ports collection makefile for:	avida
# Date created:		17 April 2002
# Whom:			Jeremy <karlj000@unbc.ca>
#
# $FreeBSD$
#

PORTNAME=	avida
PORTVERSION=	2.0b7
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Avida is an auto-adaptive genetic system designed for ALife research

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-standard-prefix --datadir=${DATADIR} --enable-viewer
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_PERL5_BUILD=	yes
USE_REINPLACE=	yes

.if !defined(WITHOUT_QT)
BUILD_DEPENDS+=	qmake:${PORTSDIR}/devel/qmake
USE_QT_VER=		3
CONFIGURE_ARGS+=	--enable-qt-viewer
CONFIGURE_ENV+=	QTDIR="${LOCALBASE}"
MAKE_ENV+=	QMAKESPEC="${LOCALBASE}/share/qt/mkspecs/freebsd-g++"		\
		QTDIR="${X11BASE}"
PLIST_SUB=	QT=""
.else
PLIST_SUB=	QT="@comment "
.endif

DIR2FIX=	source/main/functional_testsuites/default.md5sum/genesis	\
		source/main/functional_testsuites/default.tail/genesis		\
		source/main/functional_testsuites/tedious.tail/genesis		\
		source/qt-viewer/setup_genesis.cc source/support/genesis	\
		source/support/genesis.4stack source/main/config.cc source/defs.hh

pre-configure:
.for src in ${DIR2FIX}
	@${REINPLACE_CMD} -e "s|../work/|${DATADIR}/|" ${WRKSRC}/${src}
.endfor
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e "s|SUBDIRS = source doc|SUBDIRS = source|"		\
		${WRKSRC}/Makefile.in
.endif

.if !defined(WITHOUT_QT)
post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/work/qt-viewer ${PREFIX}/bin
.endif

.include <bsd.port.mk>
