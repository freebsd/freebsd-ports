# ex:ts=8
# New ports collection makefile for:	rlwrap
# Date created:			Aug 12, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	rlwrap
PORTVERSION=	0.06
CATEGORIES=	devel
MASTER_SITES=	http://utopia.knoware.nl/~hlub/uck/rlwrap/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	gnugetopt:${PORTSDIR}/devel/libgnugetopt

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lgnugetopt"
ALL_TARGET=	# empty

MANCOMPRESSED=	no
MAN1=	rlwrap.1

post-patch:
	@${PERL} -pi -e "s,%%LOCALBASE%%,${LOCALBASE},g" ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
