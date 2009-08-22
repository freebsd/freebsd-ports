# Ports collection makefile for:  pear-HTML_Page2
# Date created:			  21 January 2005
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	HTML_Page2
PORTVERSION=	0.6.0
CATEGORIES=	devel www pear
DISTNAME=	${PORTNAME}-${PORTVERSION}beta

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR base class for XHTML page generation

BUILD_DEPENDS=	${PEARDIR}/HTML/Common.php:${PORTSDIR}/devel/pear-HTML_Common
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	HTML
FILES=		Page2.php Page2/Doctypes.php Page2/Namespaces.php \
		Page2/Frameset.php Page2/Frameset/Frame.php
EXAMPLES=	Page2_NoDoctype.php Page2_Simple.php \
		Page2_Complex.php Page2_Frameset.php

post-patch:
	@${REINPLACE_CMD} -e "s###g" ${WRKSRC}/Page2.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
