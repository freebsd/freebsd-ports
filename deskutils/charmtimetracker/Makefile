# Created by: Andriy Gapon <avg@icyb.net.ua>
# $FreeBSD$

PORTNAME=	charmtimetracker
PORTVERSION=	1.6.0
CATEGORIES=	deskutils kde
MASTER_SITES=	http://nodeload.github.com/KDAB/Charm/tarball/
DISTNAME=	${PORTVERSION}
EXTRACT_SUFX=
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	avg@icyb.net.ua
COMMENT=	Time tracker

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/License.txt

WRKSRC=		${WRKDIR}/KDAB-Charm-3151d25

USES=		cmake
CMAKE_ARGS+=	-DCharm_VERSION:STRING=${PORTVERSION}
USE_KDE4=	kdehier kdeprefix
USE_QT4=	qmake_build moc_build rcc_build uic_build corelib gui network \
		qtestlib sql sql-sqlite3 xml
USE_XORG=	ice x11 xext xscrnsaver
INSTALLS_ICONS=	yes

.if !defined(NOPORTDOCS)
PORTDOCS=	ReadMe.txt License.txt
.endif

NO_STAGE=	yes
.include <bsd.port.mk>
