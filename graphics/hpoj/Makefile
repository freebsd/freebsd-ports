# ex:ts=8
# New ports collection makefile for:	hpoj
# Date created:			2003-01-30
# Whom:				Volker Stolz <stolz@i2.informatik.rwth-aachen.de>
#
# $FreeBSD$
#

PORTNAME=	hpoj
PORTVERSION=	0.91
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	hpoj
EXTRACT_SUFX=	.tgz

MAINTAINER=	stolz@i2.informatik.rwth-aachen.de
COMMENT=	"HP OfficeJet Linux driver; printing, scanning, and photo-card access"

LIB_DEPENDS=	sane.1:${PORTSDIR}/graphics/sane-backends \
		snmp.4:${PORTSDIR}/net/net-snmp4 \
		usb:${PORTSDIR}/devel/libusb
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash2

.if !defined(WITHOUT_CUPS)
WITH_CUPS=	yes
.endif

.if defined(WITH_CUPS)
LIB_DEPENDS+=	cups.2:${PORTSDIR}/print/cups-base
CONFIGURE_ARGS+=--with-cups-backend=${LOCALBASE}/libexec/cups/backend
PLIST_SUB+=	CUPS=""
.else
PLIST_SUB+=	CUPS="@comment "
.endif

INSTALLS_SHLIB=	yes

USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_PERL5=	yes

.ifndef(WITHOUT_X11)
USE_QT_VER=	3
USE_XLIB=	yes
PLIST_SUB+=	X11=""
.else
PLIST_SUB+=	X11="@comment "
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386" && ${OSVERSION} > 500000
BROKEN=	"ffs() clash, see i386/41930"
.endif

.if ${ARCH} == "alpha"
EXTRA_PATCHES=	${FILESDIR}/extra-patch-mlcd-Makefile.in \
		${FILESDIR}/extra-patch-mlcd-ParPort.h
.endif

GNU_CONFIGURE=	yes
# Necessary hacks to find libsnmp:
.if ${OSVERSION} < 510000
EXTRALDFLAGS=   -lcipher
.endif
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -L${LOCALBASE}/lib ${PTHREAD_CFLAGS}"
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS} ${EXTRALDFLAGS} -L${LOCALBASE}/lib ${PTHREAD_LIBS}"
CONFIGURE_ARGS+=	--with-snmp=${LOCALBASE}/include/ucd-snmp

.ifdef(WITHOUT_X11)
CONFIGURE_ARGS+=	--without-qt
.endif

pre-fetch:
	@${ECHO} You can disable building \'xojpanel\' and avoid the dependency on X11 and QT3 \
		by restarting the build with WITHOUT_X11
	@${ECHO} You can disable CUPS support with WITHOUT_CUPS

post-patch:
.for f in doc/info-devname.html doc/libptal.html doc/ptal-init.html doc/setup-photo-details.html \
	 doc/setup-print-details.html lib/ptal/ptal.c scripts/ptal-init.in
	@${REINPLACE_CMD} -e 's,/etc/ptal,${PREFIX}/etc/ptal,'  ${WRKSRC}/${f}
.endfor
	@${REINPLACE_CMD} -e 's,/usr/bin/perl,${PERL},' ${WRKSRC}/scripts/ptal-init.in
	@${REINPLACE_CMD} -e 's,/bin/bash,${LOCALBASE}/bin/bash,' ${WRKSRC}/scripts/ptal-init.in ${WRKSRC}/scripts/ptal-cups.in
.for f in lib/ptal lib/sane lib/hpojip
	@${REINPLACE_CMD} -e 's,CFLAGS=-O,CFLAGS+= @CFLAGS@,' ${WRKSRC}/${f}/Makefile.in
.endfor

pre-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/scripts/ptal-init ${PREFIX}/sbin
	@${INSTALL_SCRIPT} ${WRKSRC}/scripts/ptal-cups ${PREFIX}/sbin

post-install:
.ifndef(WITHOUT_X11)
	@${INSTALL_PROGRAM} ${WRKSRC}/apps/xojpanel/xojpanel ${X11BASE}/bin
.endif
	@${MV} ${PREFIX}/etc/rc.d/ptal-init.sh ${PREFIX}/etc/rc.d/020.ptal-init.sh.sample
	@${SED} 's|%%PREFIX%%|${PREFIX}|g' ${PKGDIR}/pkg-message

.include <bsd.port.post.mk>
