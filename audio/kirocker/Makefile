# New ports collection makefile for:	kirocker
# Date created:				09 August 2007
# Whom:					Jason E. Hale <bsdkaffee@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	kirocker
PORTVERSION=	4.0
PORTREVISION=	2
CATEGORIES=	audio kde
MASTER_SITES=	http://slaout.linux62.org/kirocker/downloads/ \
		http://contrib.pardus.org.tr/archives/ \
		http://darkstar.ist.utl.pt/slackware/addon/slacky/slackware-12.0/multimedia/kirocker/4.0/src/ \
		http://repository.slacky.eu/slackware-12.0/multimedia/kirocker/4.0/src/

MAINTAINER=	bsdkaffee@gmail.com
COMMENT=	Kicker applet for displaying Amarok info

RUN_DEPENDS=	amarok:${PORTSDIR}/audio/amarok

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool:15
USE_KDELIBS_VER=3
INSTALLS_ICONS=	yes

KCONFIG_COMP=	${LOCALBASE}/bin/kconfig_compiler
UIC=		${LOCALBASE}/bin/uic

.include <bsd.port.pre.mk>

pre-configure:
.for i in exportadvises framechooser themechooser themeeditor themeexporter
	cd ${WRKSRC}/src && ${UIC} -o $i.h $i.ui
.endfor
	cd ${WRKSRC}/src && ${KCONFIG_COMP} kirocker.kcfg settings.kcfgc

.include <bsd.port.post.mk>
