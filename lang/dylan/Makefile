# New ports collection makefile for:    Dylan
# Date created:         23 Jan 1998
# Whom:                 housel@acm.org
#
# $FreeBSD$
#

PORTNAME=	dylan
PORTVERSION=	2.3.4
CATEGORIES=	lang
MASTER_SITES=	ftp://berlin.ccc.de/pub/gd/src/                        \
		ftp://berlin.ccc.de/pub/gd/FreeBSD/                    \
		ftp://folk.federated.com/pub/gd/src/                   \
		ftp://folk.federated.com/pub/gd/FreeBSD/               \
		ftp://ftp.ntua.gr/pub/lang/gwydion/src/                \
		ftp://ftp.ntua.gr/pub/lang/gwydion/FreeBSD/            \
		ftp://ftp.infodrom.north.de/pub/unix/language/dylan/gwydion/src/ \
		ftp://ftp.infodrom.north.de/pub/unix/language/dylan/gwydion/FreeBSD/ \
		ftp://ftp.fu-berlin.de/pub/unix/languages/dylan/src/   \
		ftp://ftp.fu-berlin.de/pub/unix/languages/dylan/FreeBSD/
DISTNAME=	gd-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} d2c-${PORTVERSION}-FreeBSD.gz
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	housel@acm.org

RUN_DEPENDS=	libtool:${PORTSDIR}/devel/libtool

WRKSRC=		${WRKDIR}/gd-${PORTVERSION}

USE_GMAKE=	yes
GNU_CONFIGURE=  yes
CONFIGURE_ARGS= --srcdir=$(WRKSRC)
CONFIGURE_ENV=	D2C="$(WRKDIR)/d2c -p$(WRKSRC)/d2c/compiler/platforms.descr"

PLIST_SUB=	DYLANVER="${PORTVERSION}" DYLANARCH="x86-freebsd-elf-gcc"

INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	%%PREFIX%%/lib/dylan/%%DYLANVER%%/%%DYLANARCH%%
USE_GMAKE=	yes
USE_LIBTOOL=	yes
MAKEFILE=	GNUmakefile
ALL_TARGET=	default

MAN1=		d2c.1 make-dylan-app.1 melange.1 mindy.1 mindycomp.1
MAN5=		platforms.descr.5
MAN7=		dylan.7 gwydion.7

post-extract:
	$(GUNZIP_CMD) -c $(DISTDIR)/d2c-$(PORTVERSION)-FreeBSD.gz >$(WRKDIR)/d2c
	${CHMOD} ugo+x $(WRKDIR)/d2c

.include <bsd.port.mk>
