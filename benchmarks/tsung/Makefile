# New ports collection makefile for:	tsung
# Date created:	   04 June 2007
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	tsung
PORTVERSION=	1.2.1
CATEGORIES=	benchmarks
MASTER_SITES=	http://tsung.erlang-projects.org/dist/
DIST_SUBDIR=	erlang

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Multi-protocol distributed load testing tool

BUILD_DEPENDS=	erlc:${PORTSDIR}/lang/erlang
RUN_DEPENDS=	erl:${PORTSDIR}/lang/erlang \
		bash:${PORTSDIR}/shells/bash \
		gnuplot:${PORTSDIR}/math/gnuplot \
		${SITE_PERL}/${PERL_ARCH}/Template.pm:${PORTSDIR}/www/p5-Template-Toolkit

BROKEN=		fails to install
DEPRECATED=	"${BROKEN}"
EXPIRATION_DATE=	2008-01-22

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-erlang=${LOCALBASE}
USE_GMAKE=	yes
USE_PERL5=	yes

MAN1=		tsung.1

PLIST_SUB+=	VERSION="${PORTVERSION}"

post-patch:
	${REINPLACE_CMD} -E 's!datadir)/man!prefix)/man!' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
