# New ports collection makefile for:   efax-gtk
# Whom:                                Jean-Baptiste Quenot <jb.quenot@caraldi.com>
# Date Created:                        2004-02-29 10:33:43
#
# $FreeBSD$
#

PORTNAME=		efax-gtk
PORTVERSION=		3.0.12
PORTREVISION=	3
CATEGORIES=		comms
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=		.src.tgz

MAINTAINER=		jbq@caraldi.com
COMMENT=		GUI front end for the efax fax program

LIB_DEPENDS=		sigc-1.2.5:${PORTSDIR}/devel/libsigc++12
RUN_DEPENDS=		ggv:${PORTSDIR}/print/ggv

USE_GHOSTSCRIPT_RUN=	yes
USE_GNOME=		gtk20
GNU_CONFIGURE=		yes
MAN1=			efax.1 efix.1 efax-gtk.1

post-install:
	@${ECHO}
	@${ECHO_CMD} "********************************************************************************"
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD} "********************************************************************************"
	@${ECHO}

.include <bsd.port.mk>
