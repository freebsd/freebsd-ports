# ex:ts=8
# Ports collection makefile for:	tardy
# Date created:			Jan 14, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	tardy
PORTVERSION=	1.12
CATEGORIES=	archivers
MASTER_SITES=	http://tardy.sourceforge.net/

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Manipulate the file headers in tar archive files in various ways

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=		tardy.1
PLIST_FILES=	bin/tardy

post-patch:
.for var in CFLAGS LDFLAGS
	@${REINPLACE_CMD} -e 's|^\(${var}\)\ =\ \(.*\)|\1 ?= \2|' \
		${WRKSRC}/Makefile.in
.endfor

.include <bsd.port.mk>
