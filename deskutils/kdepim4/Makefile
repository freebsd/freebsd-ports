# New ports collection makefile for:	KDE PIM
# Date created:				2 March 2001
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kdepim
PORTVERSION=	${KDE_VERSION}
CATEGORIES=	deskutils mail news kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION:S/.0//}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Personal Information Management tools for KDE

USE_KDELIBS_VER=3
PREFIX=		${KDE_PREFIX}

USE_BZIP2=	yes
USE_BISON=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes

INSTALLS_SHLIB=	yes
LDCONFIG_DIRS+=	%%PREFIX%%/lib %%PREFIX%%/lib/kde3
KDE_BUILD_PLIST=yes

.if exists(${LOCALBASE}/bin/pilot-link)
WITH_KPILOT=	yes
.endif

.if exists(${LOCALBASE}/bin/gnokii)
WITH_GNOKII=	yes
.endif

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"
.include <bsd.port.pre.mk>

.if defined(WITH_GNOKII)
LIB_DEPENDS+=	gnokii.1:${PORTSDIR}/comms/gnokii
.endif # defined ($(WITH_GNOKII))

.if defined(WITH_KPILOT)
LIB_DEPENDS=	mal:${PORTSDIR}/palm/libmal \
		pisock:${PORTSDIR}/palm/pilot-link
PLIST_APPEND+=	plist.kpilot
.endif # defined ($(WITH_KPILOT))

pre-configure:
	${REINPLACE_CMD} -e 's|-ldl||' ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's|-lgnokii|-lgnokii -liconv -lintl|' ${WRKSRC}/configure

.include <bsd.port.post.mk>
