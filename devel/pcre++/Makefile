# ex:ts=8
# Ports collection makefile for:	pcre++
# Date created:			Jan 12, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	pcre++
PORTVERSION=	0.9.5
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.daemon.de/scip/Apps/pcre++/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A wrapper class around the pcre library

LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre

PCRE_CONFIG?=	${LOCALBASE}/bin/pcre-config

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="`${PCRE_CONFIG} --cflags`" \
		LDFLAGS="`${PCRE_CONFIG} --libs`"
INSTALLS_SHLIB=	yes

MAN3=		Pcre.3
PLIST_SUB=	VERSION=${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|-O -g|\@CXXFLAGS\@|g' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
