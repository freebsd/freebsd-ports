# ports collection makefile for:	fam
# Date created:				20 February 2001
# Whom:					Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=	fam
PORTVERSION=	2.6.4
CATEGORIES=	devel
MASTER_SITES=	ftp://oss.sgi.com/projects/fam/download/
DISTNAME=	${PORTNAME}-oss-${PORTVERSION}

MAINTAINER=	ishmael27@home.com

USE_AUTOMAKE_VER=14
USE_LIBTOOL=	yes
USE_GMAKE=	yes
PATCH_STRIP=	-p1
INSTALLS_SHLIB=	yes

MAN1=		fam.1m
MAN3=		fam.3x

post-install:
	@${INSTALL_SCRIPT} -m 751 ${FILESDIR}/fam.sh.sample ${PREFIX}/etc/rc.d/fam.sh.sample
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
