# New ports collection makefile for:	koffice
# Date created:				Sun May 14 2000 16:33:15
# Whom:					Will Andrews <will@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	koffice
PORTVERSION=	1.1.1
PORTEPOCH=	1
CATEGORIES=	editors kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/koffice-${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org

BUILD_DEPENDS=	autoconf213:${PORTSDIR}/devel/autoconf213 \
		automake14:${PORTSDIR}/devel/automake14
LIB_DEPENDS=	iconv.2:${PORTSDIR}/converters/iconv

USE_KDELIBS_VER=2
USE_PYTHON=	yes
PYTHON_VERSION=	python2.1
USE_BZIP2=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
.if defined(PARALLEL_PACKAGE_BUILD) || defined(WANT_KDE_FINAL)
CONFIGURE_ARGS+=--enable-final
.endif
.if defined(PARALLEL_PACKAGE_BUILD) || defined(WANT_KDE_NDEBUG)
CONFIGURE_ARGS+=--disable-debug
.else
CONFIGURE_ARGS+=--enable-debug
STRIP=''
.endif
USE_GMAKE=	yes

post-patch:
	@${PERL} -pi -e "s@Icon=killustrator@Icon=kontour@g" \
		${WRKSRC}/templates/Illustration.desktop
	@${PERL} -pi -e "s@KIllustrator@Kontour@g" \
		${WRKSRC}/templates/Illustration.desktop

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
	find ${WRKSRC} -name Makefile.in | xargs ${PERL} -pi -e \
		"s@LIBPYTHON =@LIBPYTHON= ${PTHREAD_LIBS}@g"
	${PERL} -pi -e "s@la_LIBADD =@la_LIBADD= ${PTHREAD_LIBS}@g" \
		${WRKSRC}/kivio/plugins/*/Makefile.in
	${PERL} -pi -e "s@Exec=kivio@Exec=env LD_PRELOAD=/usr/lib/libc_r.so kivio@g" \
		${WRKSRC}/kivio/kiviopart/kivio.desktop

post-install:
	${MV} ${PREFIX}/bin/kivio ${PREFIX}/bin/kivio.real
	${INSTALL_SCRIPT} ${FILESDIR}/kivio.sh ${PREFIX}/bin/kivio

.include <bsd.port.mk>
