# New ports collection makefile for:	automake18
# Date created:		15 Feb 2003
# Whom:			Udo Schweigert
#
# $FreeBSD$
#

PORTNAME=	automake
PORTVERSION=	1.8.4
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	automake
DISTNAME=	automake-${PORTVERSION}

MAINTAINER=	ade@FreeBSD.org
COMMENT=	GNU Standards-compliant Makefile generator (version 1.8)

WANT_AUTOCONF_VER=259
WANT_AUTOCONF_RUN=yes
BUILD_VERSION=	18
PLIST_SUB=	BUILD_VERSION=${BUILD_VERSION}
LATEST_LINK=	automake${BUILD_VERSION}
USE_BZIP2=	yes
USE_PERL5=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	AUTOCONF=autoconf259 AUTOHEADER=autoheader259 MAKEINFO=makeinfo
CONFIGURE_ARGS=	--program-suffix=${BUILD_VERSION}
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_REINPLACE=	yes

.if defined(USE_AUTOMAKE) || defined(USE_AUTOMAKE_VER)
pre-everything::
	@${ECHO} ===========================================================
	@${ECHO} "You have 'USE_AUTOMAKE' or 'USE_AUTOMAKE_VER' variables"
	@${ECHO} "defined either in environment or in make(1) arguments."
	@${ECHO} "Please undefine them and try again."
	@${ECHO} ===========================================================
	@${FALSE}
.endif # defined(USE_AUTOMAKE) || defined(USE_AUTOMAKE_VER)

post-patch:
	@(cd ${WRKSRC}/doc && \
		${RM} -f *.info && \
		${MV} automake.texi automake${BUILD_VERSION}.texi && \
		${REINPLACE_CMD} -E 's,(automake)\.(info),\1${BUILD_VERSION}\.\2,g' automake${BUILD_VERSION}.texi && \
		${REINPLACE_CMD} -E 's,(automake)\.(info|texi),\1${BUILD_VERSION}\.\2,g' Makefile.in \
	)

.include <bsd.port.mk>
