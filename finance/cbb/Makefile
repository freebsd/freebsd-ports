# New ports collection Makefile for:	cbb
# Date created:			24 September, 1998
# Whom:				kline
#
# $FreeBSD$
#

PORTNAME=	cbb
PORTVERSION=	0.8.1
PORTREVISION=	1
CATEGORIES=	finance deskutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-0.8%20%28stable%29/${PORTVERSION}

MAINTAINER=	kline@thought.org
COMMENT=	Checkbook balancing tool

RUN_DEPENDS=	wish8.2:${PORTSDIR}/x11-toolkits/tk82

NO_BUILD=	yes
USE_PERL5=	yes
GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|PERL = /usr/bin/perl|PERL = ${PERL5}|" \
			-e "s|WISH = /usr/bin/wish|WISH = ${LOCALBASE}/bin/wish8.2|" \
			-e "s|DESTDIR =||" ${WRKSRC}/Makefile
	@${REINPLACE_CMD} "s|DESTDIR =||" ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|$$destdir/bin|$$prefix/bin|' \
			-e 's|$$destdir/lib/cbb|$$prefix/lib/cbb|' \
			${WRKSRC}/install.pl
	@${REINPLACE_CMD} -e "s|=wish|=wish8.2|" -e 's|=""wish""|=""wish8.2""|' \
			${WRKSRC}/configure

.include <bsd.port.mk>
