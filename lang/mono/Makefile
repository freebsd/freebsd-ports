# New ports collection makefile for:   mono
# Date created:        22 July 2002
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mono
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://mono.ximian.com/archive/${PORTVERSION}/

MAINTAINER=	coop9211@uidaho.edu
COMMENT=	An open source implementation of .NET Development Framework

USE_REINPLACE=	yes
USE_BISON=	yes
USE_GNOME=	gnomehack glib20 pkgconfig
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--program-transform-name=\'\' \
		--with-gc=included \
		--with-nptl=no

MAN1=		cert2spc.1 certmgr.1 chktrust.1 cilc.1 disco.1 gacutil.1 \
		genxs.1 ilasm.1 makecert.1 mcs.1 mint.1 mono.1 \
		monoburg.1 monodis.1 monop.1 monostyle.1 oldmono.1 secutil.1 \
		setreg.1 signcode.1 sn.1 soapsuds.1 sqlsharp.1 wsdl.1 xsd.1
MAN5=		mono-config.5

ONLY_FOR_ARCHS=	i386

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
EXTRA_PATCHES=	${FILESDIR}/extra-patch-signbit
.elif ${OSVERSION} < 502113
IGNORE=	"Does not work on 5.X before 502113"
.endif

.include <bsd.port.post.mk>
