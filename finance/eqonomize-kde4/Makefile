# New ports collection makefile for:	eqonomize
# Date created:				6 August 2007
# Whom:					Yinghong.Liu <relaxbsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	eqonomize
PORTVERSION=	0.5
CATEGORIES=	finance
MASTER_SITES=	SF

MAINTAINER=	relaxbsd@gmail.com
COMMENT=	A peronal accounting software

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
