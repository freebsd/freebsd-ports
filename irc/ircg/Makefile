# New ports collection makefile for:	iRCG
# Date created:		2005-09-21
# Whom:			Alexander Novitsky <alecn2002@yandex.ru>
#
# $FreeBSD$
#

PORTNAME=	iRCG
PORTVERSION=	2.7
CATEGORIES=	irc
MASTER_SITES=	http://www.matthiaswinkelmann.com/files/

MAINTAINER=	alecn2002@yandex.ru
COMMENT=	Gateway betwean IRC server and PHP-powered Web server

LIB_DEPENDS=	st.1:${PORTSDIR}/devel/st

WRKSRC=		${WRKDIR}/${DISTNAME:U}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-st=${LOCALBASE}

.include <bsd.port.mk>
