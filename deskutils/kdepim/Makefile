# New ports collection makefile for:	KDE PIM
# Date created:				2 March 2001
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kdepim
PORTVERSION=	2.2.2
CATEGORIES=	deskutils kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org

BUILD_DEPENDS=	autoconf213:${PORTSDIR}/devel/autoconf213 \
		automake14:${PORTSDIR}/devel/automake14 \
		objprelink:${PORTSDIR}/devel/objprelink
LIB_DEPENDS=	pisock.4:${PORTSDIR}/palm/pilot-link

USE_KDELIBS_VER=2
USE_BISON=	yes
USE_BZIP2=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-objprelink \
		--with-extra-includes=${LOCALBASE}/pilot/include \
		--with-extra-libs=${LOCALBASE}/pilot/lib
.if defined(PARALLEL_PACKAGE_BUILD) || defined(WANT_KDE_FINAL)
CONFIGURE_ARGS+=--enable-final
.endif
.if defined(PARALLEL_PACKAGE_BUILD) || defined(WANT_KDE_NDEBUG)
CONFIGURE_ARGS+=--disable-debug
.endif
QTCPPFLAGS=	-I${LOCALBASE}/pilot/include -L${LOCALBASE}/pilot/lib
QTLDFLAGS=	${QTCPPFLAGS}
CONFIGURE_ENV+=	LIBS="${QTLDFLAGS}"
MAKE_ENV=	${CONFIGURE_ENV}
USE_GMAKE=	yes

pre-configure:
	${MKDIR} ${WRKSRC}/auto-bin
.for AC in autoconf autoheader
	${LN} -sf ${LOCALBASE}/bin/${AC}213 ${WRKSRC}/auto-bin/${AC}
.endfor
.for AM in automake aclocal
	${LN} -sf ${LOCALBASE}/bin/${AM}14 ${WRKSRC}/auto-bin/${AM}
.endfor
	cd ${WRKSRC} && env PATH=${WRKSRC}/auto-bin:$$PATH \
		${GMAKE} -f Makefile.cvs
	find ${WRKSRC}/kpilot \( -name Makefile.in -o -name Makefile.am \) | \
		xargs ${PERL} -pi -e \
		"s@LDFLAGS =@LDFLAGS=-L${LOCALBASE}/pilot/lib@g"
	find ${WRKSRC}/libical -name Makefile.in | xargs ${PERL} -pi -e \
		"s|INSTALL = \@INSTALL\@|INSTALL=${INSTALL} ${COPY} -o ${BINOWN} -g ${BINGRP}|g"

.include <bsd.port.mk>
