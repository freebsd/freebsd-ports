# Ports collection makefile for:	vstr
# Date created:		11 February 2004
# Whom:			Robert Schlotterbeck <robert@rs.tarrant.tx.us>
#
# $FreeBSD$
#

PORTNAME=	vstr
PORTVERSION=	1.0.15
CATEGORIES=	devel
MASTER_SITES=	http://www.and.org/vstr/1.0.15/ \
		http://www.and.org/vstr/latest/	\
		http://freebsd.unixfreunde.de/sources/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	General purpose string library for C

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack pkgconfig
INSTALLS_SHLIB=	yes

MAN3=		vstr.3 vstr_const.3

.pre-configure:
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} -e 's| Documentation||' ${WRKSRC}/Makefile.in
.endif

regression-test:
	(cd ${WRKSRC} &&	\
	${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check)

.include <bsd.port.mk>
