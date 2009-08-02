# New ports collection makefile for:	posadis
# Date Created:				27 Feb 2003
# Whom:					Sergei Kolobov <sergei@kolobov.com>
#
# $FreeBSD$
#

PORTNAME=	posadis
PORTVERSION=	0.60.5
PORTREVISION=	4
CATEGORIES=	dns ipv6
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Domain Name Server (DNS) implementation

LIB_DEPENDS=	poslib.0:${PORTSDIR}/devel/poslib

USE_AUTOTOOLS=	autoconf:262 libltdl:22 libtool:22
USE_LDCONFIG=	yes
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
