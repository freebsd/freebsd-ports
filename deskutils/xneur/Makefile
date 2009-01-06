# New ports collection makefile for:	xneur
# Date created:		19 January 2007
# Whom:			Alex "lissyara" Keda <admin@lissyara.su>
#
# $FreeBSD$
#

PORTNAME=	xneur
PORTVERSION=	0.9.2
CATEGORIES=	russian
MASTER_SITES=	http://dists.xneur.ru/release-${DISTVERSION}/tgz/ CENKES

MAINTAINER=	admin@lissyara.su
COMMENT=	Auto keyboard switcher

LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre \
		aspell:${PORTSDIR}/textproc/aspell

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static --libdir=${PREFIX}/lib/xneur
USE_BZIP2=	yes
USE_XORG=	x11 xpm
USE_GCC=	4.2+
USE_LDCONFIG=	yes
USE_GSTREAMER=	yes
MAKE_ARGS=	pkgconfigdir=${PREFIX}/libdata/pkgconfig
#DATADIR=	${SHAREDIR}/${PORTNAME}
MAN1=		xneur.1
MAN5=		xneurrc.5

post-patch:
	@${REINPLACE_CMD} -e '/^CFLAGS=/s|="|="$$CFLAGS |' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/^am__strip_dir/s#`;#|sed -Ee \
		"s/^(dict.dist|proto|proto3|langdef|regexp|xneurrc|xneurrc-be|xneurrc-uk|xneurrc-fr|xneurrc-ro|xneurrc-de|xneurrc-kz|dict)$$$$/\\1.dist/"`;#' \
		${WRKSRC}/etc/Makefile.in ${WRKSRC}/etc/Makefile.am

post-install:
	@for i in ${PREFIX}/etc/xneur/*.dist ;\
		do ${CP} -np $$i $${i%.dist}; done

.include <bsd.port.mk>
