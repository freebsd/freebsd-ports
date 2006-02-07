# New ports collection makefile for:	shtool
# Date created:			26-Apr-1999
# Whom:				Ralf S. Engelschall
#
# $FreeBSD$
#

PORTNAME=	shtool
PORTVERSION=	2.0.5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:S/$/:GNU/} ${MASTER_SITE_OSSP:S/$/:OSSP/}
MASTER_SITE_SUBDIR=	${PORTNAME}/:GNU tool/${PORTNAME}/:OSSP
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:GNU,OSSP

MAINTAINER=	vd@FreeBSD.org
COMMENT=	The GNU Portable Shell Tool

USE_PERL5_BUILD=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=		shtool-arx.1 shtool-echo.1 shtool-fixperm.1 shtool-install.1 \
		shtool-mdate.1 shtool-mkdir.1 shtool-mkln.1 shtool-mkshadow.1 \
		shtool-move.1 shtool-path.1 shtool-platform.1 shtool-prop.1 \
		shtool-rotate.1 shtool-scpp.1 shtool-slo.1 shtool-subst.1 \
		shtool-table.1 shtool-tarball.1 shtool-version.1 \
		shtool.1 shtoolize.1

.include <bsd.port.mk>
