# New ports collection makefile for:	lirc
# Date created:		4 January 2003
# Whom:			Mike Heffner <mikeh@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	lirc
PORTVERSION=	0.6.6
PORTREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	lirc

MAINTAINER=	mikeh@FreeBSD.org
COMMENT=	Linux Infared Remote Control

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

USE_XLIB=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-driver=any --disable-manage-devices

MAN1=		irexec.1 ircat.1 irpty.1 irrecord.1 irw.1 irxevent.1 \
		mode2.1 smode2.1 xmode2.1 rc.1
MAN8=		lircd.8 lircmd.8

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
