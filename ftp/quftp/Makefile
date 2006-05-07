# New ports collection makefile for:	quftp
# Date created:				10 December 2003
# Whom:					Frank Laszlo <laszlof@vonostingroup.com>
#
# $FreeBSD$
#

PORTNAME=	quftp
PORTVERSION=	1.0.7
PORTREVISION=	2
CATEGORIES=	ftp
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	quftp

MAINTAINER=	laszlof@vonostingroup.com
COMMENT=	A scriptable FTP client

LIB_DEPENDS=	readline.5:${PORTSDIR}/devel/readline

GNU_CONFIGURE=	yes

CFLAGS+=	${PTHREAD_CFLAGS} -L${LOCALBASE}/lib ${PTHREAD_LIBS}
CONFIGURE_ENV=	CFLAGS="${CFLAGS}"
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=		quftp.1
PLIST_FILES=	bin/quftp

pre-configure:
	@${REINPLACE_CMD} -e 's|-O6|-O2|g' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
