# New ports collection makefile for:	ssed
# Date created:		28 May 2002
# Whom:			verm
#
# $FreeBSD$
#

PORTNAME=	ssed
PORTVERSION=	3.58
CATEGORIES=	editors textproc
MASTER_SITES=	http://king.rett.polimi.it/~paolob/seders/ssed/
DISTNAME=	sed-${PORTVERSION}

MAINTAINER=	verm@drunkmonk.net

LIB_DEPENDS=	intl.2:${PORTSDIR}/devel/gettext \
		iconv:${PORTSDIR}/converters/libiconv

CONFIGURE_ARGS=	--with-libiconv-prefix=${LOCALBASE} --program-prefix=s

MAN1=	ssed.1

.include <bsd.port.mk>
