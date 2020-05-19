# Created by: James Bailie <jimmy@mammothcheese.ca>
# $FreeBSD$

PORTNAME=	munger
PORTVERSION=	5.12
CATEGORIES=	lang
MASTER_SITES=	http://www.mammothcheese.ca/

MAINTAINER=	jimmy@mammothcheese.ca
COMMENT=	Static lisp interpreter with text processing abilities

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libtre.so:textproc/libtre

USES=		ncurses
MAKE_ENV=	INSTALL_PROGRAM="${INSTALL_PROGRAM}" INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		INSTALL_DATA="${INSTALL_DATA}" INSTALL_MAN="${INSTALL_MAN}" \
		MKDIR="${MKDIR}"

DATADIR=	${PREFIX}/share/${PORTNAME}-${PORTVERSION}

OPTIONS_DEFINE=	SQLITE
OPTIONS_DEFAULT=	SQLITE

SQLITE_USES=	sqlite:3
SQLITE_MAKE_ARGS=	-DWITH_SQL

post-patch:
	@${REINPLACE_CMD} -e 's|lcurses|lncurses|' ${WRKSRC}/Makefile

.include <bsd.port.mk>
