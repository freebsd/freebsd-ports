# New ports collection makefile for:    gnustep-base
# Date created:         17 April 2001
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnustep-base
.if defined(WITH_GNUSTEP_DEVEL)
PORTVERSION=	1.9.0
.else
PORTVERSION=	1.8.0
.endif
CATEGORIES=	lang devel
MASTER_SITES=	${MASTER_SITE_GNUSTEP}
MASTER_SITE_SUBDIR=	core

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	GNUstep Foundation library

LIB_DEPENDS+=	xml2.5:${PORTSDIR}/textproc/libxml2

PREFIX=		${LOCALBASE}/GNUstep
NO_MTREE=	yes
ETCDIR=		${LOCALBASE}/etc
USE_AUTOCONF=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-procfs
CONFIGURE_TARGET=
USE_GMAKE=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_CONFIGURE=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
MAKEFILE=
MAKE_FLAGS=	OPTFLAG="${CFLAGS}"
CFLAGS+=	-I${LOCALBASE}/include/libxml2/libxml
BREAKS_IF_PEDANTIC=	yes
PLIST_SUB+=	MAJORVERSION=${PORTVERSION:C/([0-9]).*/\1/1}
PLIST_SUB+=	LOCALBASE=${LOCALBASE}

.if defined(WITHOUT_OPENSSL)
CONFIGURE_ARGS+=	--disable-openssl
.else
USE_OPENSSL=	yes
.endif

.include <bsd.port.pre.mk>

TARGLIB!=	(cd ${PORTSDIR}/${GNUSTEP_OBJC_PORT} && make -V TARGLIB)

post-extract:
	@${SED} -e "s=%%PREFIX%%=${LOCALBASE}=" \
		-e "s=%%TARGLIB%%=${TARGLIB}=" ${FILESDIR}/GNUstep.sh \
		> ${WRKSRC}/GNUstep.sh

post-install:
	-@${MKDIR} ${ETCDIR}/rc.d
	${INSTALL_SCRIPT} ${WRKSRC}/GNUstep.sh ${ETCDIR}/rc.d/GNUstep.sh
	${INSTALL_DATA} ${FILESDIR}/gdomap_if ${ETCDIR}

test:
	@(cd ${WRKSRC}/Testing && . ${SYSTEMDIR}/Makefiles/GNUstep.sh; ${GMAKE})

.include <bsd.port.post.mk>
