# New ports collection makefile for:    libexif
# Date created:        Tue Feb 26 19:02:44 MST 2002
# Whom:                Peter Schmiedeskamp
#
# $FreeBSD$
#

PORTNAME=	libexif
PORTVERSION=	0.5.0
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	pschmied@qwest.net

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig
RUN_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

post-patch:
	@${PERL} -pi -e 's|-g -Wall||g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${PERL} -pi -e \
		's|\$$\(libdir\)/pkgconfig|\$$\(prefix\)/libdata/pkgconfig|g'

.include <bsd.port.mk>
