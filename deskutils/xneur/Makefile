# New ports collection makefile for:	xneur
# Date created:		19 January 2007
# Whom:			Alex "lissyara" Keda <admin@lissyara.su>
#
# $FreeBSD$
#

PORTNAME=	xneur
PORTVERSION=	0.5.0
CATEGORIES=	russian
MASTER_SITES=	http://dists.xneur.ru/release-0.5.0/tgz/ CENKES

MAINTAINER=	admin@lissyara.su
COMMENT=	Auto keyboard switcher

LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
USE_XLIB=	yes
USE_BZIP2=	yes
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e '/^am__strip_dir/s#`;#|sed -Ee \
		"s/^(dict.dist|proto|proto3|langdef|regexp|xneurrc|xneurrc-be|xneurrc-uk|dict)$$$$/\\1.dist/"`;#' \
		${WRKSRC}/etc/Makefile.in ${WRKSRC}/etc/*/Makefile.in

post-install:
	@for i in ${PREFIX}/etc/xneur/*.dist ${PREFIX}/etc/xneur/*/*.dist;\
		do ${CP} -np $$i $${i%.dist}; done

.include <bsd.port.mk>
