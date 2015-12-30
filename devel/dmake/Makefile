# Created by: nils@guru.ims.uni-stuttgart.de
# $FreeBSD$

PORTNAME=	dmake
PORTVERSION=	4.12.20150309
CATEGORIES=	devel

MAINTAINER=	office@FreeBSD.org
COMMENT=	Another hyper make utility

LICENSE=	GPLv1

USE_GITHUB=	yes
GH_ACCOUNT=	mohawk2
GH_TAGNAME=	e5588b0

USES=		autoreconf:autoconf
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--datarootdir=${DATADIR}

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/dmake.tf ${STAGEDIR}${PREFIX}/man/man1/dmake.1

.include <bsd.port.mk>
