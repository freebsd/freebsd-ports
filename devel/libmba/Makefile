# ex:ts=8
# Ports collection makefile for:	libmba
# Date Created:			Sep 24, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libmba
PORTVERSION=	0.3.6
CATEGORIES=	devel
MASTER_SITES=	http://users.erols.com/mballen/libmba/src/

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	A collection of C modules potentially useful to any project

LIB_DEPENDS=	expat.4:${PORTSDIR}/textproc/expat2

SHLIB_MAJOR=	0

USE_REINPLACE=	yes
CFLAGS=		-I${LOCALBASE}/include -L${LOCALBASE}/lib
MAKE_ENV=	SHLIB_MAJOR="${SHLIB_MAJOR}" INSTDIR=${PREFIX}
ALL_TARGET=	# empty
INSTALLS_SHLIB=	yes

PLIST_SUB=	SHLIB_MAJOR="${SHLIB_MAJOR}"

MANCOMPRESSED=	yes
MAN3=	domnode.3m hexdump.3m msgno.3m hashmap.3m linkedlist.3m stack.3m

post-patch:
	@${REINPLACE_CMD} -e "s|/usr|${PREFIX}|g" \
		-e "s|gcc|${CC}|g" ${WRKSRC}/Makefile

.include <bsd.port.mk>
