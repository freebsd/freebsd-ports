# New ports collection makefile for:	libjconv
# Date created:		12 Jan 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	libjconv
PORTVERSION=	2.8.1
CATEGORIES=	japanese
MASTER_SITES=	http://www.kondara.org/libjconv/

MAINTAINER=	knu@FreeBSD.org

LIB_DEPENDS=	iconv.3:${PORTSDIR}/converters/libiconv
#RUN_DEPENDS=	${LOCALBASE}/libexec/iconv/iso-2022-jp.so:${PORTSDIR}/converters/iconv-extra

MAKE_ARGS=	NOPROFILE=true
INSTALLS_SHLIB=	yes

post-patch:
	${PERL} -i -pe 's,!!LOCALBASE!!,${LOCALBASE},' ${WRKSRC}/info.c

post-extract:
	${CP} ${FILESDIR}/Makefile* ${WRKSRC}/

.include <bsd.port.mk>
