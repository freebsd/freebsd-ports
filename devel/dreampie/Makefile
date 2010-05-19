# New ports collection makefile for:	dreampie
# Date created:			14 May 2010
# Whom:				Ju Pengfei <jupengfei@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	dreampie
PORTVERSION=	1.0.2
CATEGORIES=	devel python
MASTER_SITES=	http://launchpadlibrarian.net/40048492/

MAINTAINER=	jupengfei@gmail.com
COMMENT=	DreamPie is a Python shell which is designed to be reliable and fun

USE_GNOME=	pygtk2 pygtksourceview
USE_PYTHON=	yes
USE_PYDISTUTILS=yes

MAN1=		dreampie.1

pre-patch:
	@${REINPLACE_CMD} -e "s|share/man/man1|man/man1|" ${WRKSRC}/setup.py

.include <bsd.port.mk>
