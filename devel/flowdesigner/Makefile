# ex:ts=8
# Ports collection makefile for:	flowdesigner
# Date created:			Apr 14, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	flowdesigner
PORTVERSION=	0.8.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	FlowDesigner-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A free (GPL) "data flow oriented" development environment

LIB_DEPENDS=	fftw.2:${PORTSDIR}/math/fftw \
		gtkextra.17:${PORTSDIR}/x11-toolkits/gtkextra

USE_GNOME=	pkgconfig libxml2 libgnomeui
USE_GCC=	3.3
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${X11BASE}/include" \
		LDFLAGS="-L${X11BASE}/lib"
CONFIGURE_ARGS=	--disable-vflow
USE_GMAKE=	yes

.include <bsd.port.pre.mk>

post-install:
.for dir in ${PREFIX}/include/${PORTNAME} ${PREFIX}/share/${PORTNAME}
	@${FIND} ${dir} ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${dir} -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
.endfor

.include <bsd.port.post.mk>
