# Created by: Edwin Groothuis <edwin@mavetju.org>
# $FreeBSD$

PORTNAME=	liquidwar
PORTVERSION=	5.6.5
CATEGORIES=	games
MASTER_SITES=	http://www.ufoot.org/download/liquidwar/v5/${PORTVERSION}/ \
		http://liquidwar.sunsite.dk/archive/ \
		SAVANNAH \
		http://ufoot.hd.free.fr/pub/archive/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	You control an army of liquid and have to try and eat your opponents

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	liballeg.so:devel/allegro

USES=		gmake python:2.7,build

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-doc-info \
		--disable-doc-pdf \
		--disable-doc-ps \
		--disable-target-opt
MAKE_ARGS=	DATADIR=${DATADIR} \
		GAMEDIR=${PREFIX}/bin \
		MANDIR=${PREFIX}/man/man6
INSTALL_TARGET=	install_nolink

BINARY_ALIAS=	python=${PYTHON_CMD}

OPTIONS_DEFINE=	ASM DOCS

ASM_CONFIGURE_OFF=	--disable-asm
DOCS_CONFIGURE_OFF=	--disable-doc-html \
			--disable-doc-man \
			--disable-doc-txt

.include <bsd.port.mk>
