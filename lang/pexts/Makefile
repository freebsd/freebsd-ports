# New ports collection makefile for:	pike
# Date created:		21 Jan 2002
# Whom:			kiwi@oav.net
#
# $FreeBSD$
#

PORTNAME=	pexts
PORTVERSION=	20020121
PORTREVISION=	4
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.oav.net/pkg_freebsd/distfiles/ \
		http://ftp.oav.net/pkg_freebsd/distfiles/ \
		http://grendel.firewall.com/caudium-pkg/
DISTNAME=	pexts-snapshot-${PORTVERSION}

MAINTAINER=	kiwi@oav.net
COMMENT=	Third party Pike 7.2 extensions

BUILD_DEPENDS=	pike:${PORTSDIR}/lang/pike72/
RUN_DEPENDS=	pike:${PORTSDIR}/lang/pike72/
LIB_DEPENDS=	mhash:${PORTSDIR}/security/mhash/ \
		mcrypt:${PORTSDIR}/security/libmcrypt/

WRKSRC=		${WRKDIR}/pexts

PIKEVERSION=	7.2.570

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--without-debug

.include <bsd.port.pre.mk>

PLIST_SUB+=	PIKEVERSION=${PIKEVERSION}

USE_GMAKE=	yes

pre-configure:
	@${ECHO} ${CONFIGURE_ARGS}

.include <bsd.port.post.mk>
