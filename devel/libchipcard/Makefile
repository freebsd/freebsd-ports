# Ports collection makefile for: LibChipCard
# Date created:                  19 January 2003
# Whom:                          Martin Preuss<martin@libchipcard.de>
#
# $FreeBSD$
#

PORTNAME=	libchipcard
PORTVERSION=	0.8
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	libchipcard

MAINTAINER=	martin@libchipcard.de
COMMENT=	"A library for easy access to chipcards"

LIB_DEPENDS=	pcsclite.0:${PORTSDIR}/devel/pcsc-lite

USE_GMAKE=	yes
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_TARGET=
CONFIGURE_ARGS+=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL} \
		--with-distri=freebsd

MAN1=		ctfstool.1 chipcardd.1 geldkarte.1 hbcicard.1 \
		kvkd.1 memcard.1 libchipcard-config.1 readertest.1

MAN5=		libchipcard.conf.5 chipcardc.conf.5 chipcardd.conf.5

post-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/freebsd/chipcardd.sh ${PREFIX}/etc/rc.d
	@${SED} -e 's,%%PREFIX%%,${PREFIX},' ${PKGMESSAGE}

.include <bsd.port.mk>
