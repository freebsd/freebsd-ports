# New ports collection makefile for:	KDE PIM
# Date created:				2 March 2001
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kdepim
PORTVERSION=	${KDE_VERSION}
PORTREVISION=	1
CATEGORIES=	deskutils mail news kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Personal Information Management tools for KDE

CONFLICTS=	kdenetwork-3.1.*

USE_KDELIBS_VER=3
PREFIX=		${KDE_PREFIX}

USE_BZIP2=	yes
USE_BISON=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes

INSTALLS_SHLIB=	yes
LDCONFIG_DIRS+=	%%PREFIX%%/lib %%PREFIX%%/lib/kde3
DO_NOT_COMPILE+=kpilot

OPTIONS=	KPILOT "Build KPilot, hotsync software for KDE" off \
		GNOKII "KAdressbook import/export for Nokia phones" off

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"
.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/bin/gnokii)
.	if !defined(WITH_GNOKII)
GNOKII_OVERRIDE=yes
WITH_GNOKII=	yes
.	endif
.endif

.if defined(WITH_GNOKII)
LIB_DEPENDS+=	gnokii:${PORTSDIR}/comms/gnokii
.endif # defined ($(WITH_GNOKII))

.if defined(WITH_KPILOT)
RUN_DEPENDS+=	kpilot:${PORTSDIR}/palm/kpilot
.endif

.if defined(DO_NOT_COMPILE)
CONFIGURE_ENV+=DO_NOT_COMPILE="${DO_NOT_COMPILE}"
.endif # defined(DO_NOT_COMPILE)

pre-everything::
.if defined(GNOKII_OVERRIDE)
	@${ECHO_MSG}
	@${ECHO_MSG} "**********************************************************"
	@${ECHO_MSG} "*   gnokii is installed and support has been enabled     *"
	@${ECHO_MSG} "* automatically (no additional files will be installed). *"
	@${ECHO_MSG} "**********************************************************"
	@${ECHO_MSG}
.endif

pre-configure:
	${REINPLACE_CMD} -e 's|-ldl||' ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's|-lgnokii|-lgnokii -liconv -lintl|' ${WRKSRC}/configure
	${REINPLACE_CMD} -e '/^SUBDIRS/s/kpilot//g' ${WRKSRC}/doc/Makefile.in

.include <bsd.port.post.mk>
