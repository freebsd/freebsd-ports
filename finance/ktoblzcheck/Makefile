# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ktoblzcheck
PORTVERSION=	1.43
CATEGORIES=	finance german
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Check bank codes of German banks

LICENSE=	GPLv2

USES=		pathfix
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	PYTHON
OPTIONS_SUB=	yes

PYTHON_USE=			PYTHON=yes
PYTHON_CONFIGURE_ENABLE=	python

post-patch:
	@${REINPLACE_CMD} -e "s/-lstdc++//g" ${WRKSRC}/src/lib/Makefile.in

.include <bsd.port.mk>
