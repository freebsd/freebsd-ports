# New ports collection makefile for:	KDE SDK
# Date created:				2 March 2001
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kdesdk
PORTVERSION=	${KDE_VERSION}
CATEGORIES=	devel kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE Software Development Kit

LIB_DEPENDS=	db4:${PORTSDIR}/databases/db4

CONFLICTS=	umbrello-[0-9]* kcachegrind-[0-9]*

USE_KDEBASE_VER=3
PREFIX=		${KDE_PREFIX}

USE_PERL5=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes

INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	%%PREFIX%%/lib %%PREFIX%%/lib/kde3

pre-configure:
	@${REINPLACE_CMD} -e 's|-I$$ac_db_includes|-I${LOCALBASE}/include/db4|g' \
			-e 's|ac_db_name="db"|ac_db_name="db4"|g' ${WRKSRC}/configure

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"
.include <bsd.port.mk>
