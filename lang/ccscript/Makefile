# New ports collection makefile for:	ccscript
# Date created:				26 July 2000
# Whom:					David Sugar <dyfet@gnu.org>
#
# $FreeBSD$
#

PORTNAME=	ccscript
PORTVERSION=	2.5.6
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	ccscript

MAINTAINER=	ports@FreeBSD.org
COMMENT=	State-event driven class extendible C++ script interpreter

LIB_DEPENDS=	ccgnu2-1.0.0:${PORTSDIR}/devel/commoncpp

USE_GMAKE=	yes
USE_LIBTOOL=	yes
USE_AUTOCONF=	yes
WANT_AUTOCONF_VER=	257
INSTALLS_SHLIB=	yes

CONFIGURE_TARGET=

MAN3=		ScriptCommand.3cc ScriptImage.3cc ScriptInterp.3cc \
		ScriptModule.3cc ScriptSymbol.3cc Script_Locks.3cc \
		Script_Package.3cc Script_Property.3cc Script_Session.3cc

post-install:
	(cd ${WRKSRC} ; ${MAKE} man)

.include <bsd.port.mk>
