# New ports collection makefile for:	jupp
# Date created:				2010-11-15
# Whom:					Grzegorz Blach <magik@roorback.net>
#
# $FreeBSD$
#

PORTNAME=	jupp
PORTVERSION=	3.1.21
CATEGORIES=	editors
MASTER_SITES=	http://www.mirbsd.org/MirOS/dist/jupp/ \
		http://pub.allbsd.org/MirOS/dist/jupp/
DISTNAME=	joe-${PORTVERSION:C/([0-9]+\.[0-9]+)\.([0-9]+)/\1${PORTNAME}\2/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	magik@roorback.net
COMMENT=	Portable version of Joe's Own Editor from MirBSD

LICENSE=	GPLv1

CONFLICTS=	joe-[23]*

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-termidx
WRKSRC=		${WRKDIR}/${PORTNAME}

MAN1=		joe.1
MLINKS=		joe.1 jmacs.1 - jpico.1 - jstar.1 - jupp.1 - rjoe.1

pre-configure:
	@${CHMOD} +x ${WRKSRC}/configure

.include <bsd.port.mk>
