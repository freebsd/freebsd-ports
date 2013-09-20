# Created by: ijliao
# $FreeBSD$

PORTNAME=	pcre++
PORTVERSION=	0.9.5
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://www.daemon.de/idisk/Apps/pcre++/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A wrapper class around the pcre library

LIB_DEPENDS=	pcre.3:${PORTSDIR}/devel/pcre

PCRE_CONFIG?=	${LOCALBASE}/bin/pcre-config

USE_AUTOTOOLS=	libtool
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	`${PCRE_CONFIG} --cflags`
LDFLAGS+=	`${PCRE_CONFIG} --libs`
USE_LDCONFIG=	yes

MAN3=		Pcre.3
PLIST_SUB=	VERSION=${PORTVERSION}

DOCSDIR=	${PREFIX}/share/doc/lib${PORTNAME}-${PORTVERSION}

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|-O -g|\@CXXFLAGS\@|g' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
