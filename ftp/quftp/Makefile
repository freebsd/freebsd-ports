# New ports collection makefile for:	quftp
# Date created:				10 December 2003
# Whom:					Frank Laszlo <laszlof@vonostingroup.com>
#
# $FreeBSD$
#

PORTNAME=	quftp
PORTVERSION=	1.0.7
CATEGORIES=	ftp
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	quftp

MAINTAINER=	laszlof@vonostingroup.com
COMMENT=	A scriptable FTP client

LIB_DEPENDS=	readline.4:${PORTSDIR}/devel/readline

GNU_CONFIGURE=	yes

CFLAGS+=	-L${PREFIX}/lib ${PTHREAD_LIBS}
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=		quftp.1
PLIST_FILES=	bin/quftp

.include <bsd.port.mk>
