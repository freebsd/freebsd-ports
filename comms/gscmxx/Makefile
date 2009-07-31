# New ports collection makefile for:   gscmxx
# Date created:        13 May 2003
# Whom:                svmohr
#
# $FreeBSD$
#

PORTNAME=	gscmxx
PORTVERSION=	0.4.1
PORTREVISION=	5
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	svmohr@rm6.net
COMMENT=	A graphical frontend for scmxx

RUN_DEPENDS=	${SITE_PERL}/Image/Size.pm:${PORTSDIR}/graphics/p5-Image-Size \
		${SITE_PERL}/mach/Gtk:${PORTSDIR}/x11-toolkits/p5-Gtk
BUILD_DEPENDS=	${SITE_PERL}/Image/Size.pm:${PORTSDIR}/graphics/p5-Image-Size \
		${SITE_PERL}/mach/Gtk:${PORTSDIR}/x11-toolkits/p5-Gtk \
		scmxx:${PORTSDIR}/comms/scmxx \
		convert:${PORTSDIR}/graphics/ImageMagick

PERL_CONFIGURE=	YES

USE_GNOME=	gtk12
MAN1=		gscmxx.1
MAN3=		SCMxx.3

.include <bsd.port.mk>
