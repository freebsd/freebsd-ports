# Created by: Nils M Holm <nmh@t3x.org>
# $FreeBSD$

PORTNAME=	tide
PORTVERSION=	3.2.0
CATEGORIES=	devel
MASTER_SITES=	# http://www.t3x.org/files/
DISTNAME=	tide-${PORTVERSION:S/.//g}

MAINTAINER=	nmh@t3x.org
COMMENT=	Collection of classes for the T3X language

LICENSE=	BSD

BUILD_DEPENDS=	tx:${PORTSDIR}/lang/t3x
RUN_DEPENDS:=	${BUILD_DEPENDS}

ONLY_FOR_ARCHS=	i386

MAKE_ENV=	T3XDIR="${LOCALBASE}/t3x/r8"
MAKE_JOBS_UNSAFE=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
