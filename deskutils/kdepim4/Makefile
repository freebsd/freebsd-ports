# New ports collection makefile for:	KDE PIM
# Date created:				2 March 2001
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kdepim
PORTVERSION=	${KDE_VERSION}
CATEGORIES=	deskutils kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION}/src
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
KDE_BUILD_PLIST=yes

INSTALLS_SHLIB=	yes
LDCONFIG_DIRS+=	%%PREFIX%%/lib %%PREFIX%%/lib/kde3

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"
.include <bsd.port.pre.mk>

pre-configure::
	${REINPLACE_CMD} -e "s@-pedantic @@g; \
	s@/usr/local/include/libmal@${LOCALBASE}/include/libmal@g" \
	${WRKSRC}/configure

.if exists(${LOCALBASE}/bin/pilot-xfer)
WITH_KPILOT=YES
.endif # exists(${LOCALBASE}/bin/pilot-xfer)

.if defined(WITH_KPILOT)
LIB_DEPENDS+=	pisock:${PORTSDIR}/palm/pilot-link \
		mal:${PORTSDIR}/palm/libmal
PLIST_APPEND+=	plist.kpilot
.else
	@${ECHO_MSG}
	@${ECHO_MSG} "====================================================="
	@${ECHO_MSG} "If you want to compile with Palm Pilot support, hit"
	@${ECHO_MSG} "Ctrl-C right now and use \"make WITH_KPILOT=yes\""
	@${ECHO_MSG} "====================================================="
	@${ECHO_MSG}
.endif # defined(WITH_KPILOT)

.include <bsd.port.post.mk>
