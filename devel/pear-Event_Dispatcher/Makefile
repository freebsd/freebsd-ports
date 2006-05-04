# Ports collection makefile for:  pear-Event_Dispatcher
# Date created:			  15 March 2005
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	Event_Dispatcher
PORTVERSION=	1.0.0
CATEGORIES=	devel pear

MAINTAINER=	antonio@php.net
COMMENT=	PEAR dispatch notifications using PHP callbacks

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	Event
FILES=		Dispatcher.php Notification.php
EXAMPLES=	bubbling.php cancel.php debugging.php notification-class.php \
		object.php
TESTS=		Console_TestListener.php Dispatcher_testcase.php test.php

post-extract:
.for file in ${FILES}
	@${REINPLACE_CMD} -e "s|@package_version@|${PORTVERSION}|" ${WRKSRC}/${file}
.endfor

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
