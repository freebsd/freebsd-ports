# New ports collection makefile for:	ssed
# Date created:		28 May 2002
# Whom:			verm
#
# $FreeBSD$
#

PORTNAME=	ssed
PORTVERSION=	3.58
PORTREVISION=	1
CATEGORIES=	editors textproc
MASTER_SITES=	http://queen.rett.polimi.it/~paolob/seders/ssed/
DISTNAME=	sed-${PORTVERSION}

MAINTAINER=	verm@drunkmonk.net
COMMENT=	Super-sed is a heavily enhanced version of sed

LIB_DEPENDS=	intl.5:${PORTSDIR}/devel/gettext-old \
		iconv:${PORTSDIR}/converters/libiconv

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libiconv-prefix=${LOCALBASE} --program-prefix=s

MAN1=	ssed.1

.include <bsd.port.mk>
