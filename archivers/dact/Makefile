# ex:ts=8
# New ports collection makefile for:	dact
# Date created:			May 2, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	dact
PORTVERSION=	0.8.11
PORTREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	http://www.rkeene.org/devel/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	mcrypt.8:${PORTSDIR}/security/libmcrypt
.if !exists(/usr/bin/bzip2)
LIB_DEPENDS+=	bz2.1:${PORTSDIR}/archivers/bzip2
.endif

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=	dact.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dact ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/dact.conf ${PREFIX}/etc
	${INSTALL_MAN} ${WRKSRC}/Docs/dact.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
