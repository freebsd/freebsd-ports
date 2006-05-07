# ex:ts=8
# New ports collection makefile for:	hpoj
# Date created:			2003-01-30
# Whom:				Volker Stolz <stolz@i2.informatik.rwth-aachen.de>
#
# $FreeBSD$
#

PORTNAME=	hpoj
PORTVERSION=	0.91
PORTREVISION=	5
CATEGORIES=	graphics print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	hpoj
EXTRACT_SUFX=	.tgz

MAINTAINER=	vs@FreeBSD.org
COMMENT=	HP OfficeJet Linux driver; printing, scanning, and photo-card access

NOT_FOR_ARCHS=	sparc64 ia64

LIB_DEPENDS=	sane.1:${PORTSDIR}/graphics/sane-backends \
		usb:${PORTSDIR}/devel/libusb
.if defined(WITH_BASH2)
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash2
.else
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash
.endif

OPTIONS=	CUPS "CUPS support" on \
		SNMP "SNMP support (required for JetDirect)" on \
		BASH2 "Depend on older bash" off

.if defined(WITH_X11)
USE_QT_VER=	3
USE_XLIB=	yes
PLIST_SUB+=	X11=""
.else
PLIST_SUB+=	X11="@comment "
CONFIGURE_ARGS+=--without-qt
.endif

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_CUPS)
WITH_CUPS=	yes
.endif

.if !defined(WITHOUT_SNMP)
WITH_SNMP=	yes
.endif

.if defined(WITH_CUPS)
LIB_DEPENDS+=	cups.2:${PORTSDIR}/print/cups-base
CONFIGURE_ARGS+=--with-cups-backend=${LOCALBASE}/libexec/cups/backend
PLIST_SUB+=	CUPS=""
.else
CONFIGURE_ARGS+=--without-cups
PLIST_SUB+=	CUPS="@comment "
.endif

.if defined(WITH_SNMP)
LIB_DEPENDS+=	netsnmp.9:${PORTSDIR}/net-mgmt/net-snmp
CONFIGURE_ARGS+=--with-snmp=${LOCALBASE}/include/net-snmp/library
.else
CONFIGURE_ARGS+=--without-snmp
.endif

INSTALLS_SHLIB=	yes

USE_GMAKE=	yes
USE_PERL5=	yes

.if ${ARCH} == "alpha"
EXTRA_PATCHES=	${FILESDIR}/extra-patch-mlcd-Makefile.in \
		${FILESDIR}/extra-patch-mlcd-ParPort.h
.endif

GNU_CONFIGURE=	yes
# Necessary hacks to find libsnmp:
.if ${OSVERSION} < 501000
EXTRALDFLAGS=   -lcipher
.endif
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -L${LOCALBASE}/lib ${PTHREAD_CFLAGS}"
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS} ${EXTRALDFLAGS} -L${LOCALBASE}/lib ${PTHREAD_LIBS}"

pre-everything::
.if !defined(WITH_X11)
	@${ECHO} "You can enable building of xojpanel (QT) through -DWITH_X11"
.endif

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
.ifdef(WITH_X11)
	@${INSTALL_PROGRAM} ${WRKSRC}/apps/xojpanel/xojpanel ${X11BASE}/bin
.endif
	@${MV} ${PREFIX}/etc/rc.d/ptal-init.sh ${PREFIX}/etc/rc.d/020.ptal-init.sh.sample
	@${SED} 's|%%PREFIX%%|${PREFIX}|g' ${PKGDIR}/pkg-message

.include <bsd.port.post.mk>
