# ex:ts=8
# Ports collection makefile for:	K.R.S.S.
# Date created:			Apr 17, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	krss
PORTVERSION=	2.6
PORTREVISION=	1
CATEGORIES=	deskutils kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	kde@freebsd.org
COMMENT=	KDE Rich Site Summary viewer

BUILD_DEPENDS=	autoconf213:${PORTSDIR}/devel/autoconf213 \
		automake14:${PORTSDIR}/devel/automake14

LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg \
		png:${PORTSDIR}/graphics/png

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500113
BROKEN=         "Does not compile (bad C++ code)"
.endif

USE_KDEBASE_VER=3
GNU_CONFIGURE=	yes
QTCFGLIBS+=	-pthread
CONFIGURE_ENV+=	LIBQT="-lqt-mt"
USE_GMAKE=	yes
MAKE_ENV=	${CONFIGURE_ENV}

pre-configure:
	${MKDIR} ${WRKSRC}/auto-bin
.for AC in autoconf autoheader
	${LN} -sf ${LOCALBASE}/bin/${AC}213 ${WRKSRC}/auto-bin/${AC}
.endfor
.for AM in automake aclocal
	${LN} -sf ${LOCALBASE}/bin/${AM}14 ${WRKSRC}/auto-bin/${AM}
.endfor
	cd ${WRKSRC} && env PATH=${WRKSRC}/auto-bin:$$PATH \
		${GMAKE} -f Makefile.dist

.include <bsd.port.post.mk>
