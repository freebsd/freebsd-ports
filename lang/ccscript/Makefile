# New ports collection makefile for:	ccscript
# Date created:				26 July 2000
# Whom:					David Sugar <dyfet@gnu.org>
#
# $FreeBSD$
#

PORTNAME=	ccscript
PORTVERSION=	2.5.7
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gnutelephony

MAINTAINER=	ports@FreeBSD.org
COMMENT=	State-event driven class extendible C++ script interpreter

LIB_DEPENDS=	ccgnu2-1.2.1:${PORTSDIR}/devel/commoncpp

USE_GNOME=	gnometarget
USE_LIBTOOL_VER=	15
INSTALL_TARGET=	install man
INSTALLS_SHLIB=	yes

MAN3=		ScriptCommand.3cc ScriptImage.3cc ScriptInterp.3cc \
		ScriptModule.3cc ScriptSymbol.3cc Script_Locks.3cc \
		Script_Package.3cc Script_Property.3cc Script_Session.3cc

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CFLAGS+=	-fPIC
.endif

.include <bsd.port.post.mk>
