# New ports collection makefile for:	KDE PIM
# Date created:				2 March 2001
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kdepim
PORTVERSION=	${KDE_VERSION}
PORTREVISION=	7
CATEGORIES=	deskutils mail news palm kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION:S/.0//}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Personal Information Management tools for KDE

LIB_DEPENDS=	gpgme:${PORTSDIR}/security/gpgme \
		pisock:${PORTSDIR}/palm/pilot-link \
		sasl2:${PORTSDIR}/security/cyrus-sasl2

CONFLICTS=	akregator-[0-9]* kdenetwork-3.1.* kdeaddons-kontact-plugins-[0-9]* kdepim-kpilot-3.2.3

USE_KDEBASE_VER=3
PREFIX=		${KDE_PREFIX}
_NO_KDE_FINAL=	yes

USE_BZIP2=	yes
USE_BISON=	build
USE_OPENSSL=	yes
USE_AUTOTOOLS=	libtool:22
USE_GMAKE=	yes

USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-gpg=${LOCALBASE}/bin/gpg \
		--with-gpgsm=${LOCALBASE}/bin/gpgsm \
		--with-ssl-dir=${OPENSSLBASE}

OPTIONS=	GNOKII "KAdressbook import/export for Nokia phones" off \
		KITCHENSYNC "PIM synchronization utility" off

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"
.include <bsd.port.pre.mk>

.if defined(WITH_KITCHENSYNC)
LIB_DEPENDS+=	opensync.0:${PORTSDIR}/devel/libopensync022
PLIST_SUB+=	KITCHENSYNC=""
.else
PLIST_SUB+=	KITCHENSYNC="@comment "
DO_NOT_COMPILE+=kitchensync
.endif

.if exists(${LOCALBASE}/bin/gnokii)
.	if !defined(WITH_GNOKII)
GNOKII_OVERRIDE=yes
WITH_GNOKII=	yes
.	endif
.endif

.if defined(WITH_GNOKII)
LIB_DEPENDS+=	gnokii:${PORTSDIR}/comms/gnokii
.endif # defined ($(WITH_GNOKII))

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

.include <bsd.port.post.mk>
