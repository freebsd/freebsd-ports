# Created by: Yinghong.Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	eqonomize
PORTVERSION=	0.5.1
PORTREVISION=	6
CATEGORIES=	finance
MASTER_SITES=	SF/${PORTNAME}/Eqonomize%21/${PORTVERSION}
PKGNAMESUFFIX=	-kde3

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A personal accounting software package

DEPRECATED=	Depends on QT3; unmaintained
EXPIRATION_DATE=	2013-07-01

USE_GETTEXT=	yes
USE_KDELIBS_VER=3
GNU_CONFIGURE=	yes
USE_PERL5=	yes
USE_AUTOTOOLS=	libtool
INSTALLS_ICONS=	yes

DATADIR=	${PREFIX}/share/apps/${PORTNAME}
DOCSDIR=	${PREFIX}/share/doc/HTML/en/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} 's|%%LOCALBASE%%/bin/bash|/bin/sh|g' ${WRKSRC}/configure

.include <bsd.port.mk>
