# New ports collection makefile for:	opale
# Date created:		Wed Feb 25 00:43:37 UTC 2004
# Whom:                 Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	opale
PORTVERSION=	0.5
PORTREVISION=	1
CATEGORIES=	finance kde
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://orzel.freehackers.org/download/ \
		ftp://ftp.freehackers.org/pub/opale/
MASTER_SITE_SUBDIR=	lioux

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A very simple personal bank account manager for KDE and KOffice

BUILD_DEPENDS=	korganizer:${PORTSDIR}/deskutils/kdepim3
LIB_DEPENDS=	kofficecore.2:${PORTSDIR}/editors/koffice-kde3

BROKEN=		"Does not compile"

USE_KDELIBS_VER=3
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_INC_LIBTOOL_VER=	13
USE_REINPLACE=	yes
INSTALLS_SHLIB= yes

CONFIGURE_ARGS=	--with-koffice-includes=${LOCALBASE}/include \
  		--with-koffice-libs=${LOCALBASE}/lib \
		--program-prefix=''
CONFIGURE_ENV=	CFLAGS="${CFLAGS} ${PTHREAD_CFLAGS}" \
		LDFLAGS="${LDFLAGS} ${PTHREAD_LIBS}"

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's|-O2||g' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
