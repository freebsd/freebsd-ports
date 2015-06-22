# Created by: FUJIMOTO Kensaku <fujimoto@oscar.elec.waseda.ac.jp>
# $FreeBSD$

PORTNAME=	automake
PORTVERSION=	1.4.6
PORTREVISION=	8
CATEGORIES=	devel
MASTER_SITES=	GNU
PKGNAMESUFFIX=	14
DISTNAME=	automake-1.4-p6

# note: before committing to this port, contact portmgr to arrange for an
# experimental ports run.  Untested commits may be backed out at portmgr's
# discretion.
MAINTAINER=	autotools@FreeBSD.org
COMMENT=	GNU Standards-compliant Makefile generator (legacy 1.4)

DEPRECATED=	Not used in the ports tree anymore
EXPIRATION_DATE=	2015-07-21

RUN_DEPENDS=	${AUTOCONF_DEPENDS} \
		automake-wrapper:${PORTSDIR}/devel/automake-wrapper

USE_AUTOTOOLS=	autoconf:env
BUILD_VERSION=	1.4
PLIST_SUB=	BUILD_VERSION=${BUILD_VERSION}
USES=		cpe makeinfo perl5
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	MAKEINFO="makeinfo --no-split"
CONFIGURE_ARGS=	--program-suffix=-${BUILD_VERSION}
INFO=		automake-${BUILD_VERSION}
CPE_VENDOR=	gnu

STRIP=		# none

post-patch:
	@${MV} ${WRKSRC}/automake.texi ${WRKSRC}/automake-${BUILD_VERSION}.texi

.include <bsd.port.mk>
