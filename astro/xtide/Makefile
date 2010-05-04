# New ports collection makefile for:   xtide
# Date created:        30 August 1997
# Whom:                Brion Moss <brion@queeg.com>
#
# $FreeBSD$
#

PORTNAME=	xtide
PORTVERSION=	2.10
PORTREVISION=	4
CATEGORIES=	astro geography
MASTER_SITES=	ftp://ftp.flaterco.com/xtide/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		libtcd-2.2.4.tar.bz2 \
		harmonics-dwf-20091227-free.tar.bz2
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX} \
		libtcd-2.2.4.tar.bz2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Harmonic tide clock and tide predictor

LIB_DEPENDS=	png.6:${PORTSDIR}/graphics/png

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
MAN1=		tide.1
PLIST_FILES=	bin/tide bin/xttpd %%DATADIR%%/harmonics.tcd

MAN8=		xttpd.8
PLIST_DIRS=	%%DATADIR%%

.if defined(WITHOUT_X11)
PKGNAMESUFFIX=  -nox11
ALL_TARGET= 	tide xttpd
.else
USE_XORG=	xpm xaw
USE_GNOME=	gnometarget
MAN1+=		xtide.1
PLIST_FILES+=	bin/xtide
.endif

CPPFLAGS=	-I../libtcd-2.2.4 -I${LOCALBASE}/include/libpng
LDFLAGS=	-L../libtcd-2.2.4/.libs -L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

post-extract:
	@cd $(DISTDIR);${TAR} xzf ${DISTDIR}/harmonics-dwf-20091227-free.tar.bz2
	@$(MV) $(DISTDIR)/harmonics-dwf-20091227-free.tcd \
		 ${WRKSRC}/harmonics.tcd

post-patch:
	@${REINPLACE_CMD} -e 's|== yes|= yes|g' ${WRKDIR}/libtcd-2.2.4/configure
	@${REINPLACE_CMD} -e 's|/usr/X11R6|${LOCALBASE}|g' \
		-e 's|png_check_sig|png_sig_cmp|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/usr/X11R6|${LOCALBASE}|g' ${WRKSRC}/configure
.for file in Global.cc HarmonicsPath.cc wvsrtv.cc
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/${file}
.endfor

pre-configure:
	@cd ${WRKDIR}/libtcd-2.2.4 \
		&& ${SETENV} ${CONFIGURE_ENV} \
			CC="${CC}" CFLAGS="${CFLAGS}" \
			CXX="${CXX}" CXXFLAGS="${CXXFLAGS}" \
			${SH} ./configure --disable-shared \
			${CONFIGURE_ARGS} \
		&& ${SETENV} ${MAKE_ENV} ${GMAKE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tide ${PREFIX}/bin
.if !defined(WITHOUT_X11)
	${INSTALL_PROGRAM} ${WRKSRC}/xtide ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xtide.1 ${MANPREFIX}/man/man1
.endif
	${INSTALL_PROGRAM} ${WRKSRC}/xttpd ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/tide.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/xttpd.8 ${MAN8PREFIX}/man/man8
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/harmonics.tcd ${DATADIR}

.include <bsd.port.post.mk>
