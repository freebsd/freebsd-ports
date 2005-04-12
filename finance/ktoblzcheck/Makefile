# New ports collection makefile for:    ktoblzcheck
# Date created:         25 November 2003
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ktoblzcheck
PORTVERSION=	1.0
CATEGORIES=	finance german
MASTER_SITES=	http://ktoblzcheck.sourceforge.net/download/:misc \
		${MASTER_SITE_SOURCEFORGE:S/$/:main/}
MASTER_SITE_SUBDIR=	${PORTNAME}/:main
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:main ${DATAFILE}:misc
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Check bank codes of German banks

EXTRACT_DEPENDS=unzip:${PORTSDIR}/archivers/unzip

USE_GMAKE=	yes
USE_LIBTOOL_VER=	15
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
INSTALLS_SHLIBS=	yes

MAN1=		ktoblzcheck.1

DATAFILE=	bankdata.zip

post-extract:
	@unzip -qo ${DISTDIR}/${DATAFILE} -d ${WRKSRC}/src/bankdata

.include <bsd.port.mk>
