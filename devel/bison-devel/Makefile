# Ports collection makefile for:  bison-devel
# Date created:			  20 Nov 2004
# Whom:				  NAKATA, Maho <maho@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bison
PORTVERSION=	1.875d
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU_ALPHA}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMESUFFIX=	-devel
DISTNAME=	bison-${PORTVERSION}

MAINTAINER=	openoffice@FreeBSD.org
COMMENT=	Alpha version of bison

BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4
RUN_DEPENDS=	${BUILD_DEPENDS}

CONFLICTS=	bison-1.7[0-9]*
NO_LATEST_LINK=	yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		bison.1
INFO=		bison

.ifdef USE_BISON
.error You have `USE_BISON' variable defined either in environment or in make(1) arguments. Please undefine and try again.
.endif

post-install:
	${LN} -sf ${PREFIX}/bin/bison ${PREFIX}/bin/bison-devel

.include <bsd.port.mk>
