# New ports collection makefile for:    mtools
# Date created:         5 October 1994
# Whom:                 jmz
#
# $FreeBSD$
#

PORTNAME=	mtools
PORTVERSION=	4.0.1
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SUNSITE} \
		http://mtools.linux.lu/
MASTER_SITE_SUBDIR=	utils/disk-management

MAINTAINER=	serg@tmn.ru
COMMENT=	A collection of tools for manipulating MSDOS files

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}" \
		ac_cv_header_malloc_h=no
CONFIGURE_ARGS=	--enable-xdf

SUB_FILES=	pkg-message

MAN1=		mattrib.1 mbadblocks.1 mcat.1 mcd.1 mclasserase.1 mcopy.1 \
		mdel.1 mdeltree.1 mdir.1 mdu.1 mformat.1 mkmanifest.1 \
		minfo.1 mlabel.1 mmd.1 mmount.1 mmove.1 mpartition.1 \
		mrd.1 mren.1 mshowfat.1 mtoolstest.1 mtools.1 mtype.1 \
		mzip.1
MAN5=		mtools.5
INFO=		mtools

.if defined(WITHOUT_ICONV)
CONFIGURE_ENV+=	ac_cv_header_iconv_h=no
.else
USE_ICONV=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -liconv
.endif

.if defined(WITHOUT_X11)
CONFIGURE_ARGS+=	--without-x
PLIST_SUB=	X11="@comment "
.else
USE_XORG=	x11 sm ice xau
PLIST_SUB=	X11=""
MAN1+=		floppyd.1 floppyd_installtest.1
.endif

post-patch:
.for file in mformat.c
	@${REINPLACE_CMD} -e 's|/etc/mtools.conf|${PREFIX}/etc/mtools.conf|g' \
		${WRKSRC}/${file}
.endfor
.for file in mtools.5 mtools.texi
	@${REINPLACE_CMD} -e 's|/usr/local/etc/|${PREFIX}/etc/|g' \
		${WRKSRC}/${file}
.endfor

post-install:
	${INSTALL_DATA} ${WRKSRC}/mtools.conf ${PREFIX}/etc/mtools.conf.sample
.if !exists(${PREFIX}/etc/mtools.conf)
	@cd ${PREFIX}/etc && ${CP} -f mtools.conf.sample mtools.conf
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
