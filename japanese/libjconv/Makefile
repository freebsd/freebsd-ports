# New ports collection makefile for:	libjconv
# Date created:		12 Jan 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	libjconv
PORTVERSION=	2.8
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.rpmlinux.com/kondara/%SUBDIR%/ \
		ftp://ftp.jp.psi.net/pub/Linux/kondara/%SUBDIR%/ \
		ftp://ftp.kddlabs.co.jp/Linux/packages/Kondara/pub/Kondara/%SUBDIR%/ \
		ftp://mirror.nucba.ac.jp/mirror/Kondara/%SUBDIR%/ \
		ftp://ftp.riken.go.jp/pub/Linux/kondara/%SUBDIR%/
MASTER_SITE_SUBDIR=	Jirai/SOURCES

MAINTAINER=	knu@FreeBSD.org

LIB_DEPENDS=	iconv.2:${PORTSDIR}/converters/iconv
RUN_DEPENDS=	${LOCALBASE}/libexec/iconv/iso-2022-jp.so:${PORTSDIR}/converters/iconv-extra

MAKE_ARGS=	NOPROFILE=true
INSTALLS_SHLIB=	yes

post-patch:
	${PERL} -i -pe 's,!!LOCALBASE!!,${LOCALBASE},' ${WRKSRC}/info.c

post-extract:
	${CP} ${FILESDIR}/Makefile* ${WRKSRC}/

.include <bsd.port.mk>
