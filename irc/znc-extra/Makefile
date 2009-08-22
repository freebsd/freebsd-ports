# New ports collection makefile for:   znc-extras
# Date created:        16 July 2009
# Whom:                terry@sucked-in.com
#
# $FreeBSD$
#

PORTNAME=	znc-extra
PORTVERSION=	0.070
CATEGORIES=	irc
MASTER_SITES=	SF/znc/${PORTNAME}/${PORTVERSION}

MAINTAINER=	terry@sucked-in.com
COMMENT=	ZNC-Extra package for ZNC Bouner

BUILD_DEPENDS=	znc:${PORTSDIR}/irc/znc

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

OPTIONS=	TCL		"Enable mod_tcl" off

.include <bsd.port.pre.mk>

.if defined(WITH_TCL)
USE_TCL=	84+
.include "${PORTSDIR}/Mk/bsd.tcl.mk"
CONFIGURE_ARGS+=--enable-tcl --with-tcl=${TCL_LIBDIR}
.else
CONFIGURE_ARGS+=--without-tcl
.endif

# ZNC Directories
ZNC_WEBADMIN=	${PREFIX}/share/znc/webadmin
ZNC_WEBADMIN_SKINS=	${PREFIX}/share/znc/webadmin/skins

post-install:
	${CHMOD} 755 ${ZNC_WEBADMIN}
	${CHMOD} 755 ${ZNC_WEBADMIN_SKINS}

.include <bsd.port.post.mk>
