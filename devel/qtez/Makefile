# New ports collection makefile for:	qtez
# Date created:				14 May 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	qtez
PORTVERSION=	0.93.5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://qtez.ibl.sk/qtez/download/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_QT_VER=	2
USE_AUTOMAKE=	yes
AUTOMAKE=	automake -a -i && ${PERL} automoc
USE_LIBTOOL=	yes
CONFIGURE_ENV=	QTDIR="${X11BASE}" QTEZ="${PREFIX}/share/qtez"
MAKE_ENV=	QTEZ="${PREFIX}/share/qtez"
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

.if ${MACHINE_ARCH} == "alpha"
CFLAGS+=	-O0
.endif

pre-configure:
	@cd ${WRKSRC}/src && ${SH} ./autolinks.sh

post-install:
	@${SED} -e "s:/usr/X11R6:${PREFIX}:g" ${PKGMESSAGE}

.include <bsd.port.post.mk>
