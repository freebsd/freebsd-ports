# Ports collection makefile for:  pear-HTML_Form
# Date created:			  27 October 2004
# Whom:				  Antonio Carlos Venancio Junior (<antonio@php.net>)
#
# $FreeBSD$
#

PORTNAME=	HTML_Form
PORTVERSION=	1.2.0
CATEGORIES=	devel pear

MAINTAINER=	antonio@php.net
COMMENT=	PEAR simple HTML form package

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_REINPLACE=	yes

CATEGORY=	HTML
FILES=		Form.php
TESTS=		form.phpt

post-extract:
	@${MV} ${WRKSRC}/HTML/* ${WRKSRC}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"

post-patch:
	@${REINPLACE_CMD} -e "s|@include_path@|${PREFIX}/${LPEARDIR}|g" \
		${WRKSRC}/tests/${TESTS}

.include <bsd.port.post.mk>
