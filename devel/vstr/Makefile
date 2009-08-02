# Ports collection makefile for:	vstr
# Date created:		11 February 2004
# Whom:			Robert Schlotterbeck <robert@rs.tarrant.tx.us>
#
# $FreeBSD$
#

PORTNAME=	vstr
PORTVERSION=	1.0.15
CATEGORIES=	devel
MASTER_SITES=	http://freebsd.unixfreunde.de/sources/ \
		http://sce-tindy.tecnik93.com/FreeBSD/others_ports/${PORTNAME}/ \
		http://www.and.org/vstr/1.0.15/ \
		http://www.and.org/vstr/latest/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	General purpose string library for C

USE_AUTOTOOLS=	libtool:22
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack pkgconfig
USE_LDCONFIG=	yes

MAN3=		vstr.3 vstr_const.3

post-patch:
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} -e 's| Documentation||' ${WRKSRC}/Makefile.in
.endif

post-install:
.if defined(NOPORTDOCS)
	cd ${WRKSRC}/Documentation && ${GMAKE} install-man3
.endif

regression-test:
	(cd ${WRKSRC} &&	\
	${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check)

.include <bsd.port.mk>
