# New ports collection makefile for:	ical
# Date created:		30 January 2001
# Whom:			Takeshi MUTOH <mutoh@info.nara-k.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	ical
PORTVERSION=	2.2
PORTREVISION=	2
CATEGORIES=	japanese deskutils tk
MASTER_SITES=	ftp://ftp.sco.com/skunkware/src/shellutil/ \
		ftp://ftp.sunet.se/pub/vendor/sco/skunkware/src/shellutil/ \
		ftp://ftp.netsw.org/netsw/X11/Tools/Desktop/ \
		ftp://ftp.sunsite.org.uk/Mirrors/ftp.sco.com/skunkware/src/shellutil/

PATCH_SITES=	http://www-jlc.kek.jp/~fujiik/mklinux/Packages/dr3/JRPMS/ical/SOURCES/
PATCHFILES=	ical-2.2-jp1.patch
PATCH_DIST_STRIP=	-p1

MAINTAINER=	mutoh@openedu.org
COMMENT=	A calendar application (Japanese)

LIB_DEPENDS=	tk80jp:${PORTSDIR}/japanese/tk80

EXTRA_PATCHES=	${.CURDIR}/files/patch-*

MASTERDIR=	${.CURDIR}/../../deskutils/ical
MD5_FILE=	${.CURDIR}/distinfo

USE_XORG=	x11
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tclconfig=${PREFIX}/lib/tcl8.0jp \
		--with-tclhdir=${PREFIX}/include/tcl8.0jp \
		--with-tclsh=${PREFIX}/bin/tclsh8.0jp \
		--with-tkconfig=${PREFIX}/lib/tk8.0jp \
		--with-tkhdir=${PREFIX}/include/tk8.0jp

MAN1=		ical.1

.include <bsd.port.mk>
