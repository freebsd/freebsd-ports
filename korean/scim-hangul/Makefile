# New ports collection makefile for:    ko-scim-hangul
# Date created:		13 Oct 2005
# Whom:			CHOI Junho <cjh@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	scim-hangul
PORTVERSION=	0.2.1
#PORTREVISION=	2
CATEGORIES=	korean
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=scim

MAINTAINER=	cjh@FreeBSD.org
COMMENT=	SCIM IMEngine module for Korean(Hangul) input

BUILD_DEPENDS=	scim:${PORTSDIR}/textproc/scim
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_X_PREFIX=	yes
USE_ICONV=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500035
BUILD_DEPENDS+=	${LOCALBASE}/lib/libstlport_gcc.so:${PORTSDIR}/devel/stlport
RUN_DEPENDS+=	${LOCALBASE}/lib/libstlport_gcc.so:${PORTSDIR}/devel/stlport
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include -I${LOCALBASE}/include/stlport" \
		LDFLAGS="-L${LOCALBASE}/lib -lstlport_gcc ${PTHREAD_LIBS}"
.else
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include -D__STDC_ISO_10646__" \
		LDFLAGS="-L${LOCALBASE}/lib"
.endif

post-install:
	@${CAT} ${PKGMESSAGE}
	@${ECHO}
	@${ECHO} To display this message again, type \`pkg_info -D ${PKGNAME}\'
	@${ECHO}

.include <bsd.port.post.mk>
