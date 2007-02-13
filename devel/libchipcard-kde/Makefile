# Ports collection makefile for: LibChipCard-KDE
# Date created:                  19 January 2003
# Whom:                          Martin Preuss<martin@libchipcard.de>
#
# $FreeBSD$
#

PORTNAME=		libchipcard-kde
PORTVERSION=		0.9
PORTREVISION=		1
CATEGORIES=		devel kde
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	libchipcard

MAINTAINER=		martin@libchipcard.de
COMMENT=		KDE tools for LibChipCard

LIB_DEPENDS=		chipcard.20:${PORTSDIR}/devel/libchipcard:install

USE_GMAKE=		yes
USE_AUTOTOOLS=		libtool:15
CONFIGURE_TARGET=
CONFIGURE_ARGS+=	--with-distri=freebsd --with-kde3-prefix=${LOCALBASE}\
			--with-applnk-dir=${PREFIX}/share/applnk/Utilities \
			--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_KDELIBS_VER=	3

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e 's,libkdeui.so.4,libkdeui.so,; \
		s|-lc_r|${PTHREAD_LIBS}|g' ${WRKSRC}/configure
	${REINPLACE_CMD} -e "s,libpcsclite.so.0,libpcsclite.so.1,; \
		s,/usr/local/pcsc/include,${LOCALBASE}/include/PCSC," ${WRKSRC}/configure


.include <bsd.port.post.mk>
