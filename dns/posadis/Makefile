# New ports collection makefile for:	posadis
# Date Created:				27 Feb 2003
# Whom:					Sergei Kolobov <sergei@kolobov.com>
#
# $FreeBSD$
#

PORTNAME=	posadis
PORTVERSION=	0.60.5
PORTREVISION=	1
CATEGORIES=	dns
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	sergei@FreeBSD.org
COMMENT=	Domain Name Server (DNS) implementation

LIB_DEPENDS=	poslib.0:${PORTSDIR}/devel/poslib

USE_AUTOCONF_VER=	259
USE_LIBTOOL_VER=	15
USE_LIBLTDL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

.if defined(WITH_FAM) || exists(${LOCALBASE}/lib/libfam.so)
CONFIGURE_ARGS=	--enable-fam
BUILD_DEPENDS=	${LOCALBASE}/include/fam.h:${PORTSDIR}/devel/fam
RUN_DEPENDS=	${LOCALBASE}/bin/fam:${PORTSDIR}/devel/fam
PLIST_SUB=	FAM=""
.else
CONFIGURE_ARGS=	--disable-fam
PLIST_SUB=	FAM="@comment "
.endif

PLIST_SUB+=	VERSION="${PORTVERSION}"

MAN1=		getzone.1 posadis.1 posadis-getroots.1 posask.1 poshost.1
MAN5=		posadisrc.5
DOCS=		AUTHORS ChangeLog README TODO

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
