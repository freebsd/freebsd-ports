# New ports collection makefile for:	ccscript
# Date created:				26 July 2000
# Whom:					David Sugar <dyfet@gnu.org>
#
# $FreeBSD$
#

PORTNAME=	ccscript
PORTVERSION=	2.5.7
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU:S/$/:gnu/} \
		${MASTER_SITE_SOURCEFORGE:S/$/:sf/}
MASTER_SITE_SUBDIR=	ccscript/:gnu \
			bayonne/:sf
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}:gnu \
		${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}:sf

MAINTAINER=	ports@FreeBSD.org
COMMENT=	State-event driven class extendible C++ script interpreter

LIB_DEPENDS=	ccgnu2-1.1.0:${PORTSDIR}/devel/commoncpp

USE_GNOME=	gnometarget
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install man
INSTALLS_SHLIB=	yes
USE_LIBTOOL_VER=	15

MAN3=		ScriptCommand.3cc ScriptImage.3cc ScriptInterp.3cc \
		ScriptModule.3cc ScriptSymbol.3cc Script_Locks.3cc \
		Script_Package.3cc Script_Property.3cc Script_Session.3cc

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CFLAGS+=	-fPIC
.endif

.include <bsd.port.post.mk>
