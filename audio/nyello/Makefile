# New ports collection makefile for:    nyello
# Date created:				03 Mar 2006
# Whom:				  	Alexander Botero-Lowry <alex@foxybanana.com>
#
# $FreeBSD$
#

PORTNAME=	nyello
PORTVERSION=	0.4.1
CATEGORIES=	audio
MASTER_SITES=	http://sirius.cine7.net/nyello/releases/

MAINTAINER=	alex@foxybanana.com
COMMENT=	An advanced command-line interface and shell for xmms2

BUILD_DEPENDS=	${LOCALBASE}/lib/libxmmsclient.so:${PORTSDIR}/audio/xmms2

USE_BZIP2=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ENV=	CC="${CC}" CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}" \
		CPPFLAGS="${CPPFLAGS}" CXX="${CXX}" CXXFLAGS="${CXXFLAGS}"

WRKSRC=		${WRKDIR}/${DISTNAME}
PLIST_FILES=	bin/nyello

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		Does not build on FreeBSD 4.x
.endif

.include <bsd.port.post.mk>
