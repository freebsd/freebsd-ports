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
MASTER_SITES=	${MASTER_SITE_GNU:S/$/:gnu/} \
		${MASTER_SITE_SOURCEFORGE:S/$/:sf/}
MASTER_SITE_SUBDIR=	ccaudio/:gnu \
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

MAN3=		ScriptCommand.3cc ScriptImage.3cc ScriptInterp.3cc \
		ScriptModule.3cc ScriptSymbol.3cc Script_Locks.3cc \
		Script_Package.3cc Script_Property.3cc Script_Session.3cc

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 503001
BROKEN=		"Does not compile on FreeBSD >= 5.x"
.endif
.include <bsd.port.post.mk>
