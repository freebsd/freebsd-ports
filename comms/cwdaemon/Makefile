# ports collection makefile for:	cwdaemon
# Date created:		17 Mar 2005
# Whom:			Diane Bruce <db@db.net>
#
# $FreeBSD$
#

PORTNAME=	cwdaemon
PORTVERSION=	0.9.4
CATEGORIES=	comms hamradio
MASTER_SITES=	http://www.chronos.org.uk/download/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	db

MAINTAINER=	db@FreeBSD.org
COMMENT=	Amateur Radio cw (morse code) keyer daemon

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkg-config
LIB_DEPENDS=	cw:${PORTSDIR}/comms/unixcw

INSTALL_TARGET=	install-exec
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/doc
MAN8=		cwdaemon.8

post-install:
.if !defined(NOPORTDOCS)
	cd ${WRKSRC}; ${MAKE} install-data
.else
	cd ${WRKSRC}; ${MAKE} install-man
.endif

.include <bsd.port.mk>
