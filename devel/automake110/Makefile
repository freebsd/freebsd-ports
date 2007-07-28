# New ports collection makefile for:	automake110
# Date created:		5th December 2006
# Whom:			Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	automake
PORTVERSION=	1.10
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	automake
DISTNAME=	automake-${PORTVERSION}

MAINTAINER=	ade@FreeBSD.org
COMMENT=	GNU Standards-compliant Makefile generator (1.10)

RUN_DEPENDS=	${AUTOCONF_DEPENDS} \
		automake-wrapper:${PORTSDIR}/devel/automake-wrapper

USE_AUTOTOOLS=	autoconf:261:env
BUILD_VERSION=	1.10
PLIST_SUB=	BUILD_VERSION=${BUILD_VERSION}
LATEST_LINK=	automake110
USE_BZIP2=	yes
USE_PERL5=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-suffix=-${BUILD_VERSION}
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
INFO=		automake-${BUILD_VERSION}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 600000
BUILD_DEPENDS+=	${LOCALBASE}/bin/makeinfo:${PORTSDIR}/print/texinfo
CONFIGURE_ENV+=	MAKEINFO="${LOCALBASE}/bin/makeinfo --no-split"
.else
CONFIGURE_ENV+=	MAKEINFO="makeinfo --no-split"
.endif

post-patch:
	@${RM} ${WRKSRC}/doc/*.info
	@${MV} ${WRKSRC}/doc/automake.texi \
	       ${WRKSRC}/doc/automake-${BUILD_VERSION}.texi

pre-su-install:
	@${RM} -fr ${PREFIX}/share/automake-${BUILD_VERSION}
	@${MKDIR} ${PREFIX}/share/automake-${BUILD_VERSION}
	@${MKDIR} ${PREFIX}/share/aclocal-${BUILD_VERSION}

.include <bsd.port.post.mk>
