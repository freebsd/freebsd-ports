# New ports collection makefile for:    ja-scim-skk
# Date created:		6 Apr 2005
# Whom:			Jun Mukai <mukai@jmuk.org>
#
# $FreeBSD$
#    $MCom: ports/japanese/scim-skk/Makefile,v 1.1 2006/09/30 05:17:05 ahze Exp $

PORTNAME=	scim-skk
PORTVERSION=	0.5.2
PORTREVISION=	2
CATEGORIES=	japanese
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=	scim-imengine/18121

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SCIM IMEngine module like SKK

BUILD_DEPENDS=	scim:${PORTSDIR}/textproc/scim
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_AUTOTOOLS=	libtool:15
USE_X_LIB=	yes
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

.if ${OSVERSION} < 500000
BROKEN=	does not compile on 4.x: bad C++ code
.endif

post-patch:
	@${REINPLACE_CMD} "s|LOCALBASE|${LOCALBASE}|" ${WRKSRC}/src/scim_skk_prefs.h

post-install:
	@${CAT} ${PKGMESSAGE}
	@${ECHO}
	@${ECHO} To display this message again, type \`pkg_info -D ${PKGNAME}\'
	@${ECHO}

.include <bsd.port.post.mk>
