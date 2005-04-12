# Ports collection makefile for: LibChipCard-KDE
# Date created:                  19 January 2003
# Whom:                          Martin Preuss<martin@libchipcard.de>
#
# $FreeBSD$
#

PORTNAME=		libchipcard-kde
PORTVERSION=		0.8
PORTREVISION=	3
CATEGORIES=		devel kde
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	libchipcard

MAINTAINER=		martin@libchipcard.de
COMMENT=		KDE tools for LibChipCard

LIB_DEPENDS=		chipcard.17:${PORTSDIR}/devel/libchipcard:install

USE_GMAKE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_TARGET=
CONFIGURE_ARGS+=	--with-distri=freebsd --with-kde3-prefix=${LOCALBASE}\
			--with-applnk-dir=${PREFIX}/share/applnk/Utilities \
			--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_KDELIBS_VER=	3
USE_REINPLACE=		yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502102
IGNORE=			links against conflicting thread libraries
.endif

post-patch:
	${REINPLACE_CMD} -e 's,libkdeui.so.4,libkdeui.so,' ${WRKSRC}/configure

.include <bsd.port.post.mk>
