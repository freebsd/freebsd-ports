# New ports collection makefile for:   kdesupport
# Version required:    Beta1
# Date created:        28 October 1997
# Whom:                Stefan Eßer <se@freebsd.org>
#
# $Id: Makefile,v 1.18 1999/02/06 23:21:59 se Exp $
#

DISTNAME=	kdesupport-1.1
CATEGORIES=	x11 kde
MASTER_SITES=	$(MASTER_SITE_KDE)
MASTER_SITE_SUBDIR= stable/1.1/distribution/tar/generic/source

MAINTAINER=	se@freebsd.org

USE_QT=		yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	"--prefix=$(PREFIX)" \
		"--without-libjpeg" \
		"--without-libgif" \
		"--without-libgdbm" \
		"--without-libuulib"
CONFIGURE_ENV=	CXXFLAGS="$(CFLAGS)" \
		INSTALL_SCRIPT="install -c -m 555"

.include <bsd.port.mk>

post-install:
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib
.if ${PORTOBJFORMAT} == "aout"
	${LN} -sf libQwSpriteField.so.6.0  ${PREFIX}/lib/libQwSpriteField.so
	${LN} -sf lib/libjs.so.2.0         ${PREFIX}/lib/libjs.so
	${LN} -sf lib/libmimelib.so.1.0    ${PREFIX}/lib/libmimelib.so
	${LN} -sf librdb.so.55.0           ${PREFIX}/lib/librdb.so
.endif
