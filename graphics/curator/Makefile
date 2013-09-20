# Created by: Stefan Walter <sw@gegenunendlich.de>
# $FreeBSD$

PORTNAME=	curator
PORTVERSION=	2.1
PORTREVISION=	5
CATEGORIES=	graphics www python
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Static Image Gallery Generator for web or CD-ROM galleries

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

OPTIONS_DEFINE=	PIL
PIL_DESC=	Use Python Imaging Library instead of ImageMagick

PLIST_FILES=	bin/curator
MAN1=		curator.1

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPIL}
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/PIL/__init__.py:${PORTSDIR}/graphics/py-imaging
.else
RUN_DEPENDS=	convert:${PORTSDIR}/graphics/ImageMagick
.endif

post-install:
	${INSTALL_MAN} ${FILESDIR}/curator.1 ${PREFIX}/man/man1/curator.1

.include <bsd.port.mk>
