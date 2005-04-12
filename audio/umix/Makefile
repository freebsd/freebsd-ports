# New ports collection makefile for:   umix
# Date created:        24 January 2001
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	umix
PORTVERSION=	1.0.2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Advanced tool for adjusting soundcard mixers, replacement for aumix

USE_GETOPT_LONG=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=		umix.1
PLIST_FILES=	bin/umix

post-patch:
	@${REINPLACE_CMD} -e \
		's|="/etc"|="$${prefix}/etc"|g' ${WRKSRC}/configure

.include <bsd.port.mk>
