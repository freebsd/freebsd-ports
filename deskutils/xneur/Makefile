# New ports collection makefile for:	xneur
# Date created:		19 January 2007
# Whom:			Alex "lissyara" Keda <admin@lissyara.su>
#
# $FreeBSD$
#

PORTNAME=	xneur
PORTVERSION=	0.6.1
CATEGORIES=	russian
MASTER_SITES=	http://dists.xneur.ru/release-0.6.1/tgz/ CENKES

MAINTAINER=	admin@lissyara.su
COMMENT=	Auto keyboard switcher

LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
USE_XLIB=	yes
USE_BZIP2=	yes
USE_LDCONFIG=	yes
MAKE_ARGS=	pkgconfigdir=${PREFIX}/libdata/pkgconfig

post-patch:
	@${REINPLACE_CMD} -e '/^am__strip_dir/s#`;#|sed -Ee \
		"s/^(dict.dist|proto|proto3|langdef|regexp|xneurrc|xneurrc-be|xneurrc-uk|xneurrc-fr|xneurrc-ro|dict)$$$$/\\1.dist/"`;#' \
		${WRKSRC}/etc/Makefile.in ${WRKSRC}/etc/*/Makefile.in

post-install:
	@for i in ${PREFIX}/etc/xneur/*.dist ${PREFIX}/etc/xneur/*/*.dist;\
		do ${CP} -np $$i $${i%.dist}; done

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 600000
BROKEN=		does not compile on FreeBSD 5.X
.endif

.include <bsd.port.post.mk>
