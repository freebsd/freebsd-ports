# New ports collection makefile for:	automake19
# Date created:		15 Feb 2003
# Whom:			Udo Schweigert
#
# $FreeBSD$
#

PORTNAME=	automake
PORTVERSION=	1.9.5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	automake
DISTNAME=	automake-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU Standards-compliant Makefile generator (version 1.9)

WANT_AUTOCONF_VER=259
WANT_AUTOCONF_RUN=yes
BUILD_VERSION=	19
PLIST_SUB=	BUILD_VERSION=${BUILD_VERSION}
LATEST_LINK=	automake${BUILD_VERSION}
USE_BZIP2=	yes
USE_PERL5=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	AUTOCONF=autoconf259 AUTOHEADER=autoheader259 MAKEINFO=makeinfo
CONFIGURE_ARGS=	--program-suffix=${BUILD_VERSION} \
		--infodir=${PREFIX}/info
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_REINPLACE=	yes
INFO=		automake${BUILD_VERSION}

post-patch:
	@(cd ${WRKSRC}/doc && \
		${RM} -f *.info && \
		${MV} automake.texi automake${BUILD_VERSION}.texi && \
		${REINPLACE_CMD} -E 's,(automake)\.(info),\1${BUILD_VERSION}\.\2,g' automake${BUILD_VERSION}.texi && \
		${REINPLACE_CMD} -E 's,(automake)\.(info|texi),\1${BUILD_VERSION}\.\2,g' Makefile.in \
	)
	@${REINPLACE_CMD} -e 's,%%X11BASE%%,${X11BASE},g' ${WRKSRC}/aclocal.in

pre-su-install:
	@${RM} -fr ${PREFIX}/share/automake${BUILD_VERSION}
	@${MKDIR} ${PREFIX}/share/automake${BUILD_VERSION}
	@${MKDIR} ${PREFIX}/share/aclocal${BUILD_VERSION}
	@${MKDIR} ${PREFIX}/libexec/automake${BUILD_VERSION}

post-install:
.for i in aclocal automake
	@${LN} -sf ${PREFIX}/bin/${i}${BUILD_VERSION} \
		${PREFIX}/libexec/automake${BUILD_VERSION}/${i}
.endfor

.include <bsd.port.mk>
