# Ports collection makefile for:  pear-HTML_Form
# Date created:			  27 October 2004
# Whom:				  Antonio Carlos Venancio Junior (<antonio@php.net>)
#
# $FreeBSD$
#

PORTNAME=	HTML_Form
PORTVERSION=	1.1.3
CATEGORIES=	devel www pear

MAINTAINER=	antonio@php.net
COMMENT=	Simple HTML form package

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_REINPLACE=	yes

FILES=		HTML/Form.php
TESTS=		form.phpt

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"

post-patch:
	@${REINPLACE_CMD} -e "s|@include_path@|${PREFIX}/${LPEARDIR}|g" \
		${WRKSRC}/tests/${TESTS}

.include <bsd.port.post.mk>
