# New ports collection makefile for:    ja-scim-skk
# Date created:		6 Apr 2005
# Whom:			Jun Mukai <mukai@jmuk.org>
#
# $FreeBSD$
#    $MCom: ports/japanese/scim-skk/Makefile,v 1.1 2006/09/30 05:17:05 ahze Exp $

PORTNAME=	scim-skk
PORTVERSION=	0.5.2
PORTREVISION=	6
CATEGORIES=	japanese
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=	scim-imengine/18121

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SCIM IMEngine module like SKK

BUILD_DEPENDS=	scim:${PORTSDIR}/textproc/scim
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_AUTOTOOLS=	libtool:22
USE_ICONV=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}" \
		CPPFLAGS="-I${LOCALBASE}/include -D__STDC_ISO_10646__" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} "s|LOCALBASE|${LOCALBASE}|" ${WRKSRC}/src/scim_skk_prefs.h

post-install:
	@${CAT} ${PKGMESSAGE}
	@${ECHO}
	@${ECHO} To display this message again, type \`pkg_info -D ${PKGNAME}\'
	@${ECHO}

.include <bsd.port.mk>
