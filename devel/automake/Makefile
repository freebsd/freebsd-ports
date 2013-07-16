# New ports collection makefile for:	automake
# Date created:		5th December 2006
# Whom:			Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	automake
PORTVERSION=	1.14
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	automake
DISTNAME=	automake-${PORTVERSION}

MAINTAINER=	autotools@FreeBSD.org
COMMENT=	GNU Standards-compliant Makefile generator

RUN_DEPENDS=	${AUTOCONF_DEPENDS} \
		automake-wrapper:${PORTSDIR}/devel/automake-wrapper

USE_AUTOTOOLS=	autoconf:env
BUILD_VERSION=	1.14
PLIST_SUB=	BUILD_VERSION=${BUILD_VERSION}
USE_XZ=		yes
USE_PERL5=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-suffix=-${BUILD_VERSION}
CONFIGURE_ENV+=	MAKEINFO="makeinfo --no-split"
INFO=		automake
MAN1=		aclocal-${BUILD_VERSION}-${BUILD_VERSION}.1 \
		aclocal-${BUILD_VERSION}.1 \
		automake-${BUILD_VERSION}-${BUILD_VERSION}.1 \
		automake-${BUILD_VERSION}.1

post-patch:
	@${RM} ${WRKSRC}/doc/*.info

pre-su-install:
	@${RM} -fr ${PREFIX}/share/automake-${BUILD_VERSION}
	@${MKDIR} ${PREFIX}/share/automake-${BUILD_VERSION}
	@${MKDIR} ${PREFIX}/share/aclocal-${BUILD_VERSION}

.include <bsd.port.mk>
