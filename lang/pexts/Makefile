# New ports collection makefile for:	pike
# Date created:		21 Jan 2002
# Whom:			kiwi@oav.net
#
# $FreeBSD$
#

PORTNAME=	pexts
PORTVERSION=	20020121
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.oav.net/pkg_freebsd/distfiles/ \
		http://ftp.oav.net/pkg_freebsd/distfiles/ \
		http://grendel.firewall.com/caudium-pkg/
DISTNAME=	pexts-snapshot-${PORTVERSION}

MAINTAINER=	kiwi@oav.net
COMMENT=	Third party Pike 7.2 extensions

BUILD_DEPENDS=	pike:${PORTSDIR}/lang/pike72/
LIB_DEPENDS=	mhash.2:${PORTSDIR}/security/mhash/ \
		mcrypt.8:${PORTSDIR}/security/libmcrypt/

WRKSRC=		${WRKDIR}/pexts

GNU_CONFIGURE=  yes

CONFIGURE_ARGS+= --without-debug

USE_GMAKE=	yes

pre-configure:
	@${ECHO} ${CONFIGURE_ARGS}

.include <bsd.port.mk>
