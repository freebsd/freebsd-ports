# New ports collection makefile for:	eqonomize
# Date created:				6 August 2007
# Whom:					Yinghong.Liu <relaxbsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	eqonomize
PORTVERSION=	0.5.1
PORTREVISION=	1
CATEGORIES=	finance
MASTER_SITES=	SF
PKGNAMESUFFIX=	-kde3

MAINTAINER=	cm@therek.net
COMMENT=	A personal accounting software package

USE_GETTEXT=	yes
USE_KDELIBS_VER=3
GNU_CONFIGURE=	yes
USE_PERL5=	yes
USE_AUTOTOOLS=	libtool:15
INSTALLS_ICONS=	yes

DATADIR=	${PREFIX}/share/apps/${PORTNAME}
DOCSDIR=	${PREFIX}/share/doc/HTML/en/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} 's|%%LOCALBASE%%/bin/bash|/bin/sh|g' ${WRKSRC}/configure

.include <bsd.port.mk>
